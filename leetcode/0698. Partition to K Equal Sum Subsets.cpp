// naive TLE
// sort 168ms
// sort and avoid duplicated visiting 4-8 ms

/*
we always try to put the next digit in the first subset. If there is no 
solution, trying a larger digit first will get to false conclusion earlier.
i.e. with large digit in subset, the variant of the remaining space will be small
*/

class Solution {
public:
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        int total = 0;
        for (int num : nums) total += num;
        if (total % k != 0) return false;
        
        sort(nums.begin(), nums.end(), cmp);
        vector<int> sums(k, 0);
        return backtrack(0, total / k, nums, sums);
    }
    
private:
    static bool cmp(int a, int b) {
        return a > b;
    }
    
    bool backtrack(int index, int target, vector<int>& nums, vector<int>& sums) {
        if (index == nums.size()) return true;
        for (int i = 0; i < sums.size(); ++i) {
            if (sums[i] + nums[index] > target) continue;
            
            // avoid duplicated check, if sums = [5, 2, 2, 2], curr = 1, curr will only been 
            // put into sums[1], because put into sums[2], sums[3] is the same
            int j = i - 1;
            for (; j >= 0; --j) {
                if (sums[j] == sums[i]) break;
            }
            if (j >= 0) continue;
            
            sums[i] += nums[index];
            if (backtrack(index + 1, target, nums, sums)) return true;
            sums[i] -= nums[index];
        }
        return false;
    }


// the same as above, clean code, but slower for using hashset to check duplicates
class Solution {
public:
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        int total = 0;
        for (int num : nums) total += num;
        if (total % k != 0) return false;
        
        sort(nums.begin(), nums.end(), cmp);
        vector<int> sums(k, 0);
        return backtrack(0, total / k, nums, sums);
    }
    
private:
    static bool cmp(int a, int b) {
        return a > b;
    }
    
    bool backtrack(int index, int target, vector<int>& nums, vector<int>& sums) {
        if (index == nums.size()) return true;
        unordered_set<int> visited;

        for (int i = 0; i < sums.size(); ++i) {
            if (sums[i] + nums[index] > target) continue;
            if (visited.count(sums[i])) continue;
            
            visited.insert(sums[i]);
            sums[i] += nums[index];
            if (backtrack(index + 1, target, nums, sums)) return true;
            sums[i] -= nums[index];
        }
        return false;
    }
};