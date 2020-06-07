class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        if (matrix.empty() || matrix[0].empty()) return 0;
        int m = matrix.size(), n = matrix[0].size();
        // dp[i][j] represent the edge length of the largest square ENDING at (ith, jth)
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
        int size = 0;
        for (int i = 1; i <= m; ++i) {
            for (int j = 1; j <= n; ++j) {
                if (matrix[i - 1][j - 1] == '1') {
                    // the minLength of up, left, upLeft + 1
                    dp[i][j] = min(min(dp[i][j - 1], dp[i - 1][j]), dp[i - 1][j - 1]) + 1;
                    size = max(size, dp[i][j]);
                }
            }
        }
        return size * size;
    }
};


class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        if (matrix.empty() || matrix[0].empty()) return 0;
        int m = matrix.size(), n = matrix[0].size();
        vector<int> curr(n + 1, 0), pre(n + 1, 0);
        int size = 0;
        for (int i = 1; i <= m; ++i) {
            for (int j = 1; j <= n; ++j) {
                // explicit initialization when you use dp[j] for every i
                // matrix[i - 1][j - 1] == '0', curr[j] should be 1
                curr[j] = 0;
                if (matrix[i - 1][j - 1] == '1') {
                    curr[j] = min(min(curr[j - 1], pre[j]), pre[j - 1]) + 1;
                    size = max(size, curr[j]);
                }
            }
            swap(pre, curr);
        }
        return size * size;
    }
};