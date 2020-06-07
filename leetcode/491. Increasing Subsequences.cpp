class Solution {
public:
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        vector<int> curr;
        set<vector<int>> res;  // vector<int> could not used for keys in unordered_set
        backtrack(0, nums, curr, res);
        return vector<vector<int>>(res.begin(), res.end());
    }
    
private:
    void backtrack(int start, vector<int>& nums, vector<int>& curr, set<vector<int>> &res) {
        if (curr.size() > 1) res.insert(curr);
        for (int i = start; i < nums.size(); ++i) {
            if (!curr.empty() && nums[i] < curr.back()) continue;
            curr.push_back(nums[i]);
            backtrack(i + 1, nums, curr, res);
            curr.pop_back();
        }
    }
};


class Solution {
public:
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        vector<int> curr;
        vector<vector<int>> res; 
        backtrack(0, nums, curr, res);
        return res;
    }
    
private:
    void backtrack(int start, vector<int>& nums, vector<int>& curr, vector<vector<int>> &res) {
        if (curr.size() > 1) res.push_back(curr);
        
        for (int i = start; i < nums.size(); ++i) {
            if (!curr.empty() && nums[i] < curr.back()) continue;

            // whether there are duplicates from start to i in current level
            // 4 6 7 7 ... 
            // select the first 7, do not select the second 7
            // do not select the first 7, select the seonc 7
            // the two situations are totally the same for ...
            int j = start - 1;
            for (; j >= start; --j) {
                if (nums[j] == nums[i]) break;
            }
            if (j >= start) continue;
            
            curr.push_back(nums[i]);
            backtrack(i + 1, nums, curr, res);
            curr.pop_back();
        }
    }
};


// the same as above, clean code but slower than above for creating hashset
class Solution {
public:
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        vector<int> curr;
        vector<vector<int>> res; 
        backtrack(0, nums, curr, res);
        return res;
    }
    
private:
    void backtrack(int start, vector<int>& nums, vector<int>& curr, vector<vector<int>> &res) {
        if (curr.size() > 1) res.push_back(curr);
        // record whether there are duplicates from start to i
        // next level it will be recreated, so will not affect duplicates between levels
        unordered_set<int> used; 
        for (int i = start; i < nums.size(); ++i) {
            if (!curr.empty() && nums[i] < curr.back()) continue;
            if (used.count(nums[i])) continue;  
            curr.push_back(nums[i]);
            used.insert(nums[i]);
            backtrack(i + 1, nums, curr, res);
            curr.pop_back();
        }
    }
};