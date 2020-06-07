// class Solution {
// public:
//     int numTrees(int n) {
//         if (n < 1) return 1;
//         vector<int> dp(n + 1);
//         dp[0] = 1;
//         return getBSTNum(n, dp);
//     }
    
//     int getBSTNum(int n, vector<int>& dp) {
//         if (dp[n] != 0) return dp[n];
//         for (int i = 1; i <= n; ++i) {
//             dp[n] += getBSTNum(i - 1, dp) * getBSTNum(n - i, dp);
//         }
//         return dp[n];
//     }
// };

class Solution {
public:
    int numTrees(int n) {
        if (n <= 1) return 1;
        vector<int> dp(n + 1);
        dp[0] = 1;
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= i; ++j) {
                dp[i] += dp[j - 1] * dp[i - j];
            }
        }
        return dp[n];
    }
};