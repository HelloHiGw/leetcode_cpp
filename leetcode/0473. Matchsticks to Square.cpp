// TLE
// class Solution {
// public:
//     bool makesquare(vector<int>& nums) {
//         if (nums.size() < 4) return false;
//         int total = 0;
//         for (int num : nums) total += num;
//         if (total % 4 != 0) return false;
        
//         vector<int> sums(4);
//         return backtrack(0, total / 4, nums, sums);
//     }
    
// private:
//     bool backtrack(int i, int target, vector<int>& nums, vector<int>& sums) {
//         if (i == nums.size()) return true;
//         for (int j = 0; j < 4; ++j) {
//             if (sums[j] + nums[i] > target) continue;
//             sums[j] += nums[i];
//             if (backtrack(i + 1, target, nums, sums)) return true;
//             sums[j] -= nums[i];
//         }
//         return false;
//     }
// };


/*
we always try to put the next matchstick in the first subset. If there is no 
solution, trying a longer matchstick first will get to false conclusion earlier.
*/
class Solution {
public:
    bool makesquare(vector<int>& nums) {
        if (nums.size() < 4) return false;
        int total = 0;
        for (int num : nums) total += num;
        if (total % 4 != 0) return false;

        sort(nums.begin(), nums.end(), cmp);
        vector<int> sums(4);
        return backtrack(0, total / 4, nums, sums);
    }
    
private:
    bool static cmp(int a, int b) {
        return a > b;
    }
    
    bool backtrack(int i, int target, vector<int>& nums, vector<int>& sums) {
        if (i == nums.size()) return true;
        for (int j = 0; j < 4; ++j) {
            if (sums[j] + nums[i] > target) continue;
            
            // avoid duplicated check, if sums = [5, 2, 2, 2], curr = 1, curr will only been 
            // put into sums[1], because put into sums[2], sums[3] is the same
            int k = j - 1; 
            for (; k >= 0; --k) {
                if (sums[k] == sums[j]) break;
            }
            if (k >= 0) continue;
            
            sums[j] += nums[i];
            if (backtrack(i + 1, target, nums, sums)) return true;
            sums[j] -= nums[i];
        }
        return false;
    }
};