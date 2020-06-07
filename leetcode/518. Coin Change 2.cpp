class Solution {
public:
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        // dp[i][j], the ways for the first i coins to make sum j
        vector<vector<int>> dp(n + 1, vector<int>(amount + 1, 0));
        
        // dp[i][0] means how many ways we have to use first i coins to make up the amount of 0 , 
        // so it's clear that we can have 1 way that we use none of them.
        for (int i = 0; i <= n; ++i) dp[i][0] = 1;  // coin >= 1
        
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= amount; ++j) {
                if (j < coins[i - 1]) {
                    dp[i][j] = dp[i - 1][j];
                } else {
                    dp[i][j] = dp[i - 1][j] + dp[i][j - coins[i - 1]];
                }
            }
        }
        
        return dp[n][amount];
    }
};

class Solution {
public:
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        vector<int> dp(amount + 1, 0);
        dp[0] = 1;
        
        for (int i = 1; i <= n; ++i) {
            for (int j = coins[i - 1]; j <= amount; ++j) {
                dp[j] += dp[j - coins[i - 1]];
            }
        }
        
        return dp[amount];
    }
};