class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        sort(nums.begin(), nums.end());
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
            // write by myself !
            /*
            1 1 2
            let's take the second 1, if visit[0] = true and come to second 1, it should go normally
            because a permutation with first 1 as the leading is calculating

            if visit[0] = false and come to second 1, it should stop
            because a permutation with first 1 as the leading has been calculated, if you take
            the second 1 as leading, it will generate duplicates

            */
            if (visited[i] || i && nums[i] == nums[i - 1] && !visited[i - 1]) continue;
            visited[i] = true;
            curr.push_back(nums[i]);
            backtrack(nums, visited, curr, res);
            visited[i] = false;
            curr.pop_back();
        }
    }
};