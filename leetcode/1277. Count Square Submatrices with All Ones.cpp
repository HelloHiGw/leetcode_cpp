/*
1 1
1 1
dp[2][2] = 2, it means maxSize of square bottom-right at [2, 2] is 2
meanwhile, it means two squares bottom-right at [2, 2] (length 1 and length 2)
so res += dp[i][j]
*/
class Solution {
public:
    int countSquares(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
        
        int res = 0;
        for (int i = 1; i <= m; ++i) {
            for (int j = 1; j <= n; ++j) {
                if (matrix[i - 1][j - 1] == 1) {
                    dp[i][j] = min({dp[i - 1][j - 1], dp[i - 1][j], dp[i][j - 1]}) + 1;
                    res += dp[i][j];
                }
            }
        }
        
        return res;
    }
};