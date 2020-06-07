class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> res;
        vector<int> curr;
        sort(candidates.begin(), candidates.end()); // need sort to avoid duplicates
        backtrack(target, 0, candidates, curr, res);
        return res;
    }
    
    void backtrack(int target, int start, vector<int>& nums, vector<int>& curr, vector<vector<int>>& res) {
        if (target == 0) {
            res.push_back(curr);
            return;
        }
        if (target < 0) return;
        for (int i = start; i < nums.size(); ++i) {
            if (i > start && nums[i] == nums[i - 1]) continue;  // avoid duplicates
            curr.push_back(nums[i]);
            backtrack(target - nums[i], i + 1, nums, curr, res);
            curr.pop_back();
        }
    }
};