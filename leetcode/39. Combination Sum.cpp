// class Solution {
// public:
//     vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
//         vector<vector<int>> res;
//         backtrack(0, target, 0, candidates, {}, res);
//         return res;
//     }
    
//     void backtrack(int sum, int target, int index, vector<int>& nums, vector<int> curr, vector<vector<int>>& res) {
//         if (sum == target) {
//             res.push_back(curr);
//             return;
//         }
//         if (sum > target || index == nums.size()) return;
//         // do not add current number
//         backtrack(sum, target, index + 1, nums, curr, res);
//         // add current number
//         sum += nums[index];
//         curr.push_back(nums[index]);
//         backtrack(sum, target, index, nums, curr, res);
//     }
// };


class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> res;
        vector<int> curr;
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
            curr.push_back(nums[i]);
            backtrack(target - nums[i], i, nums, curr, res);
            curr.pop_back();
        }
    }
};