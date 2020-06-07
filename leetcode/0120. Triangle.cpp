// class Solution {
// public:
//     int minimumTotal(vector<vector<int>>& triangle) {
//         vector<vector<int>> dp(triangle.size(), vector<int>(triangle.back().size(), INT_MAX));
//         for (int i = 0; i < dp.back().size(); ++i) {
//             dp.back()[i] = triangle.back()[i];
//         }
//         for (int i = triangle.size() - 2; i >= 0; --i) {
//             for (int j = 0; j < triangle[i].size(); ++j) {
//                 dp[i][j] = min(dp[i + 1][j], dp[i + 1][j + 1]) + triangle[i][j];
//             }
//         }
//         return dp[0][0];
//     }
// };


class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        vector<int> dp = triangle.back();
        for (int i = (int)triangle.size() - 2; i >= 0; --i) {
            for (int j = 0; j < triangle[i].size(); ++j) {
                dp[j] = min(dp[j], dp[j + 1]) + triangle[i][j];
            }
        }
        return dp[0];
    }
};