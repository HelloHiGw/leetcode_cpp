// class Solution {
// public:
//     int longestCommonSubsequence(string text1, string text2) {
//         int n1 = text1.size(), n2 = text2.size();
//         vector<vector<int>> dp(n1 + 1, vector<int>(n2 + 1));
//         for (int i = 1; i <= n1; ++i) {  // dp[0][...] and dp[...][0] is base case 0, we need start from index 1
//             for (int j = 1; j <= n2; ++j) {
//                 if (text1[i - 1] == text2[j - 1]) {  // dp[i] only need information of dp[i - 1], consider using two rows vector
//                     dp[i][j] = dp[i - 1][j - 1] + 1;
//                 } else {
//                     dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
//                 }
//             }
//         }
//         return dp[n1][n2];
//     }
// };


class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int n1 = text1.size(), n2 = text2.size();
        if (n1 < n2) return longestCommonSubsequence(text2, text1);
        vector<vector<int>> dp(2, vector<int>(n2 + 1));
        for (int i = 1; i <= n1; ++i) {
            int currIdx = i % 2, preIdx = 1 - currIdx;
            for (int j = 1; j <= n2; ++j) {
                if (text1[i - 1] == text2[j - 1]) {
                    dp[currIdx][j] = dp[preIdx][j - 1] + 1;
                } else {
                    dp[currIdx][j] = max(dp[preIdx][j], dp[currIdx][j - 1]);
                }
            }
        }
        return dp[n1 % 2][n2];
    }
};

/*
Obviously, the code in method 1 only needs information of previous row to
update current row. So we just use a two-row 2D array to save and update the
matching results for chars in s1 and s2.

space O(min(n1, n2))
*/