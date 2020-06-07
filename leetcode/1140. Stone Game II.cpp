class Solution {
public:
    int stoneGameII(vector<int>& piles) {
        int n = piles.size();
        vector<int> suffixSum(n);
        suffixSum[n - 1] = piles[n - 1];
        for (int i = n - 2; i >= 0; --i) {  // self and rightside suffix sum
            suffixSum[i] = suffixSum[i + 1] + piles[i];
        }
        vector<vector<int>> memo(n, vector<int>(n, -1));
        return dfs(0, 1, piles, suffixSum, memo);
    }
    
private:
    int dfs(int i, int M, vector<int>& piles, vector<int>& suffixSum, vector<vector<int>>& memo) {
        // i + 2 * M - 1 = n - 1 boundary
        if (i + 2 * M >= piles.size()) return suffixSum[i];
        if (memo[i][M] != -1) return memo[i][M];
        
        int opponentMinVal = INT_MAX;
        for (int x = 1; x <= 2 * M; ++x) {
            opponentMinVal = min(opponentMinVal, dfs(i + x, max(M, x), piles, suffixSum, memo));
        }
        // here res contains current selected and afterwards selected
        int res = suffixSum[i] - opponentMinVal;
        return memo[i][M] = res;
    }
};

/*
pretty hard to understand bottom up dp

time O(n ^ 3) ?
space O(n ^ 2)
*/
class Solution {
public:
    int stoneGameII(vector<int>& piles) {
        int n = piles.size();
        vector<int> suffixSum(n);
        suffixSum[n - 1] = piles[n - 1];
        for (int i = n - 2; i >= 0; --i) {  // self and rightside suffix sum
            suffixSum[i] = suffixSum[i + 1] + piles[i];
        }
        
        vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));
        // dp[n][1] = dp[n][2] = ... = dp[n][n] = 0 as boundary
        
        for (int i = n - 1; i >= 0; --i) {
            for (int m = 1; m <= n; ++m) {
                // if i + x - 1 = n - 1, it will get all the remaining array
                // that is i + x = n
                int opponentMinVal = INT_MAX;
                for (int x = 1; x <= 2 * m && x + i <= n; ++x) {
                    opponentMinVal = min(opponentMinVal, dp[x + i][max(x, m)]);
                }
                dp[i][m] = suffixSum[i] - opponentMinVal;
            }
        }
        
        return dp[0][1];
    }
};

