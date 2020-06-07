/*
this is 0-1 knapsack in essence
0-1 knapsack we have dp[i][j], j the the weight
here dp[i][j][k], j and k is the weight

time O(len * m * n)
space O(len * m * n)
*/
class Solution {
public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        int len = strs.size();
        // dp[i][j][k] means the maximum number of strings we can get from the first i argument strs 
        // using limited j number of '0's and k number of '1's.
        vector<vector<vector<int>>> dp(len + 1, vector<vector<int>>(m + 1, vector<int>(n + 1, 0)));

        for (int i = 1; i <= len; ++i) {
            int numZeros = 0, numOnes = 0;  // calculate current weight
            for (char ch : strs[i - 1]) {
                ch == '0' ? ++numZeros : ++numOnes;
            }
            
            for (int j = 0; j <= m; ++j) {
                for (int k = 0; k <= n; ++k) {
                    if (j < numZeros || k < numOnes) {  // cannot select current object
                        dp[i][j][k] = dp[i - 1][j][k];
                    } else {  // not select current object and select current object
                        dp[i][j][k] = max(dp[i - 1][j][k], dp[i - 1][j - numZeros][k - numOnes] + 1);
                    }
                }
            }
        }
        
        return dp[len][m][n];
    }
};


/*
time O(len * m * n)
space O(m * n)
*/
class Solution {
public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        int len = strs.size();
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));

        for (int i = 1; i <= len; ++i) {
            int numZeros = 0, numOnes = 0;  // calculate current weight
            for (char ch : strs[i - 1]) {
                ch == '0' ? ++numZeros : ++numOnes;
            }
            
            for (int j = m; j >= numZeros; --j) {
                for (int k = n; k >= numOnes; --k) {
                    dp[j][k] = max(dp[j][k], dp[j - numZeros][k - numOnes] + 1);
                }
            }
        }
        
        return dp[m][n];
    }
};