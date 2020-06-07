/*
similar to knapsack
but it is not knapsack, because in the ith stage, we must select a dice number

time O(d * target * f)
space O(d * target)
*/
class Solution {
public:
    int numRollsToTarget(int d, int f, int target) {
        const int MOD = 1e9 + 7;
        vector<vector<long>> dp(d + 1, vector<long>(target + 1, 0));
        // dp[0][j] = 0 (j >= 1)  dp[i][0] = 0 (i >= 1) OK
        dp[0][0] = 1;
        
        for (int i = 1; i <= d; ++i) {
            for (int j = 1; j <= target; ++j) {
                for (int k = 1; k <= f; ++k) {
                    // current dice gets k, the total sum will not be less than k
                    if (j < k) continue;
                    dp[i][j] = (dp[i][j] + dp[i - 1][j - k]) % MOD;
                }
            }
        }
        
        return dp[d][target];
    }
};

/*
time O(d * target * f)
space O(target)
*/
class Solution {
public:
    int numRollsToTarget(int d, int f, int target) {
        const int MOD = 1e9 + 7;
        vector<long> dp(target + 1, 0);
        
        for (int i = 1; i <= d; ++i) {
            // traps...dp[0][0] = 1, dp[i][0] = 0 (i >= 1)
            dp[0] = i == 1 ? 1 : 0;
            for (int j = target; j >= 1; --j) {
                dp[j] = 0;
                for (int k = 1; k <= f; ++k) {
                    if (j < k) continue;
                    dp[j] = (dp[j] + dp[j - k]) % MOD;
                }
            }
        }
        
        return dp[target];
    }
};