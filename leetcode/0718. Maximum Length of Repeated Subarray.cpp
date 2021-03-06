/*
same idea of Longest Common Substring, it must be continuous
*/
class Solution {
public:
    int findLength(vector<int>& A, vector<int>& B) {
        int m = A.size(), n = B.size();
        // dp[i][j] is the length of longest common subarray ending with 
        // the ith A and jth B (nums[i-1] and nums[j-1])
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
        int res = 0;
        
        for (int i = 1; i <= m; ++i) {
            for (int j = 1; j <= n; ++j) {
                dp[i][j] = A[i - 1] == B[j - 1] ? dp[i - 1][j - 1] + 1 : 0;
                res = max(res, dp[i][j]);
            }
        }
        
        return res;
    }
};