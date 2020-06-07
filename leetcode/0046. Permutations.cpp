class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<int> curr;
        vector<vector<int>> res;
        vector<bool> visited(nums.size());
        backtrack(nums, visited, curr, res);
        return res;
    }
    
    void backtrack(vector<int>& nums, vector<bool>& visited, vector<int>& curr, vector<vector<int>>& res) {
        if (curr.size() == nums.size()) {
            res.push_back(curr);
            return;
        }
        for (int i = 0; i < nums.size(); ++i) {
            if (visited[i]) continue;
            visited[i] = true;
            curr.push_back(nums[i]);
            backtrack(nums, visited, curr, res);
            visited[i] = false;
            curr.pop_back();
        }
    }
};