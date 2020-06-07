class Solution {
public:
    int minSteps(int n) {
        vector<int> dp(n + 1);
        
        for (int i = 2; i <= n; ++i) {
            dp[i] = i;  // at most i times
            for (int j = i - 1; j > 1; --j) {
                // copy(1), pastes (i / j - 1) total i / j
                // i cannot understand break here in the most upvoted answer
                if (i % j == 0) dp[i] = min(dp[i], dp[j] + i / j);
            }
        }
        
        return dp[n];  // dp[1] = 0;
    }
};


class Solution {
public:
    int minSteps(int n) {
        vector<int> dp(n + 1);
        
        for (int i = 2; i <= n; ++i) {
            dp[i] = i;  
            for (int j = i / 2; j > 1; --j) {
                if (i % j == 0) dp[i] = min(dp[i], dp[j] + i / j);
            }
        }
        
        return dp[n];
    }
};