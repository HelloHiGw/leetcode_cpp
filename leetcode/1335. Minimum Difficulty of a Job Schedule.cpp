// class Solution {
// public:
//     int minDifficulty(vector<int>& jobDifficulty, int d) {
//         int n = jobDifficulty.size();
//         if (n < d) return -1;
//         const int INF = 0x3fffffff;
//         vector<vector<int>> dp(d + 1, vector<int>(n + 1, INF));
//         dp[0][0] = 0;
//         for (int i = 1; i <= d; ++i) {
//             for (int j = i; j <= n; ++j) {  // dp[i][j] = inf if j < i (tasks < days)
//                 int maxD = 0;
//                 for (int k = j - 1; k >= i - 1; --k) {
//                     maxD = max(maxD, jobDifficulty[k]);  // j - 1 + 1 - 1
//                     dp[i][j] = min(dp[i][j], dp[i - 1][k] + maxD);
//                 }
//             }
//         }
//         return dp[d][n];
//     }
// };

// /*
// time complexity O(dnn) space complexity O(dn)

// dp[i][j] the minimum difficulty to finish j tasks in i days (both 1-based)

// initilization
// dp[0][0] = 0, dp[*][*] = inf

// transition
// dp[i][j] = min(dp[i - 1][k], max(A[k + 1], A[k + 2], ..., A[j]))
// i - 1 <= k < j 
// there must be at least a job in the ith day, so k < j (should not arrange j tasks all in i - 1 days)
// there must be at least i - 1 jobs in i - 1 days, otherwise can not arrange jobs to each day

// */


class Solution {
public:
    int minDifficulty(vector<int>& jobDifficulty, int d) {
        int n = jobDifficulty.size();
        if (n < d) return -1;
        const int INF = 0x3fffffff;
        vector<int> dp(n + 1, INF);
        dp[0] = 0;
        for (int i = 1; i <= d; ++i) {
            for (int j = n; j >= i; --j) {  // need dp[i - 1][j - *] so we enumerate from right to left
                dp[j] = INF;  // initialization for every i
                int maxD = 0;
                for (int k = j - 1; k >= i - 1; --k) {
                    maxD = max(maxD, jobDifficulty[k]);
                    dp[j] = min(dp[j], dp[k] + maxD);
                }
            }
        }
        return dp[n];
    }
};