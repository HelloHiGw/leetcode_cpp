class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        const int INF = 0x3fffffff;
        int n = coins.size();
        
        // dp[i][j], the fewest number of coins for the first i to make amount j
        // INF, denotes the first i coins cannot make amount j
        vector<vector<int>> dp(n + 1, vector<int>(amount + 1, INF));
        
        // cannot set dp[0][j] = 0 (1 <= j <= amount), because it is impossible(INF), not 0
        for (int i = 0; i <= n; ++i) {
            dp[i][0] = 0;
        }
        
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= amount; ++j) {
                if (j < coins[i - 1]) {
                    dp[i][j] = dp[i - 1][j];
                } else {
                    dp[i][j] = min(dp[i - 1][j], dp[i][j - coins[i - 1]] + 1);
                }
            }
        }
        
        return dp[n][amount] >= INF ? -1 : dp[n][amount];
    }
};


class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        const int INF = 0x3fffffff;
        int n = coins.size();
        
        vector<int> dp(amount + 1, INF);
        dp[0] = 0;
        
        for (int i = 1; i <= n; ++i) {
            for (int j = coins[i - 1]; j <= amount; ++j) {
                dp[j] = min(dp[j], dp[j - coins[i - 1]] + 1);
            }
        }
        
        return dp[amount] >= INF ? -1 : dp[amount];
    }
};