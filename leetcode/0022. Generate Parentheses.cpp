class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        backtrack(0, 0, n, "", res);
        return res;
    }
    
    void backtrack(int leftNum, int rightNum, int n, string s, vector<string> &res) {
        if (s.size() == 2 * n) {
            res.push_back(s);
            return;
        }
        if (leftNum < n) backtrack(leftNum + 1, rightNum, n, s + "(", res);
        if (rightNum < leftNum) backtrack(leftNum, rightNum + 1, n, s + ")", res);
    }
};