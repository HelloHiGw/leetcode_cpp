/*
time O(m * n)
space O(m * n)
*/
class Solution {
public:
    int minDistance(string word1, string word2) {
        int m = word1.size(), n = word2.size();
        // dp[i][j] the minimum number of steps required 
        // to make word1[0:i) and word2[0:j) the same
        vector<vector<int>> dp(m + 1, vector<int>(n + 1));
        dp[0][0] = 0;
        for (int i = 1; i <= m; ++i) dp[i][0] = i;
        for (int j = 1; j <= n; ++j) dp[0][j] = j;
        
        for (int i = 1; i <= m; ++i) {
            for (int j = 1; j <= n; ++j) {
                if (word1[i - 1] == word2[j - 1]) {
                    dp[i][j] = dp[i - 1][j - 1];
                } else {
                    // delete word1[ith] or word2[jth]
                    dp[i][j] = min(dp[i - 1][j], dp[i][j - 1]) + 1;
                }
            }
        }
        
        return dp[m][n];
    }
};


/*
find LCS and subtract it
time O(m * n)
space O(m * n)
*/
class Solution {
public:
    int minDistance(string word1, string word2) {
        int m = word1.size(), n = word2.size();
        // LCS
        vector<vector<int>> dp(m + 1, vector<int>(n + 1));
        
        for (int i = 1; i <= m; ++i) {
            for (int j = 1; j <= n; ++j) {
                if (word1[i - 1] == word2[j - 1]) {
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                } else {
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                }
            }
        }
        
        return word1.size() + word2.size() - 2 * dp[m][n];
    }
};