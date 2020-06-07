class Solution {
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> res;
        vector<int> curr;
        backtrack(k, n, 1, curr, res);
        return res;
    }
    
    void backtrack(int k, int n, int start, vector<int>& curr, vector<vector<int>>& res) {
        if (k == 0 && n == 0) {
            res.push_back(curr);
            return;
        }
        if (k < 0 || n < 0) return;
        for (int i = start; i < 10; ++i) {
            curr.push_back(i);
            backtrack(k - 1, n - i, i + 1, curr, res);
            curr.pop_back();
        }
    }
};