// class Solution {
// public:
//     vector<vector<int>> updateMatrix(vector<vector<int>>& matrix) {
//         vector<vector<int>> res(matrix.size(), vector<int>(matrix[0].size(), -1));
//         queue<pair<int, int>> que;
//         vector<vector<bool>> visited(matrix.size(), vector<bool>(matrix[0].size(), false));
//         for (int i = 0; i < matrix.size(); ++i) {
//             for (int j = 0; j < matrix[0].size(); ++j) {
//                 if (matrix[i][j] == 0) {
//                     que.push({i, j});
//                     visited[i][j] = true;
//                 }
//             }
//         }
        
//         int level = -1;
//         vector<vector<int>> dirs = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
//         while(!que.empty()) {
//             ++level;
//             for (int k = que.size(); k > 0; --k) {
//                 int i = que.front().first, j = que.front().second;
//                 que.pop();
//                 res[i][j] = level;
//                 for (const auto& d : dirs) {
//                     int ni = i + d[0], nj = j + d[1];
//                     if (isValid(ni, nj, matrix, visited)) {
//                         que.push({ni, nj});
//                         visited[ni][nj] = true;
//                     }
//                 }
//             }
//         }
//         return res;
//     }
    
// private:
//     bool isValid(int i, int j, vector<vector<int>>& matrix, vector<vector<bool>>& visited) {
//         return i >= 0 && i < matrix.size() && j >= 0 && j < matrix[0].size() && !visited[i][j];
//     }
// };


class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& matrix) {
        queue<pair<int, int>> que;
        for (int i = 0; i < matrix.size(); ++i) {
            for (int j = 0; j < matrix[0].size(); ++j) {
                if (matrix[i][j] == 0) {
                    que.push({i, j});
                } else {
                    matrix[i][j] = -1; // unreachable may be INF is more suitable
                }
            }
        }
        
        int level = 0;
        vector<vector<int>> dirs = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
        while(!que.empty()) {
            ++level;
            for (int k = que.size(); k > 0; --k) {
                int i = que.front().first, j = que.front().second;
                que.pop();
                for (const auto& d : dirs) {
                    int ni = i + d[0], nj = j + d[1];
                    if (isValid(ni, nj, matrix)) {
                        que.push({ni, nj});
                        matrix[ni][nj] = level; // here matrix also serves as visited(inQueue), you should not update matrix after que.pop()
                    }
                }
            }
        }
        return matrix;
    }
    
private:
    bool isValid(int i, int j, vector<vector<int>>& matrix) {
        return i >= 0 && i < matrix.size() && j >= 0 && j < matrix[0].size() && matrix[i][j] == -1;
    }
};



class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& matrix) {
        if (matrix.empty() || matrx[0].empty()) return {};
        int m = matrix.size(), n = matrix[0].size();
        constexpr int INF = 0x3fffffff;
        vector<vector<int>> dp(m, vector<int>(n, INF));
        
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (matrix[i][j] == 0) {
                    dp[i][j] = 0;
                } else {  // suppose the flow can only from up to down, left to right
                    if (i > 0) dp[i][j] = min(dp[i][j], dp[i - 1][j] + 1);
                    if (j > 0) dp[i][j] = min(dp[i][j], dp[i][j - 1] + 1);
                }
            }
        }
        
        for (int i = m - 1; i >= 0; --i) {
            for (int j = n - 1; j >= 0; --j) {
                if (matrix[i][j] == 1) {  // suppose the flow can only from down to up, right to left
                    if (i < m - 1) dp[i][j] = min(dp[i][j], dp[i + 1][j] + 1);
                    if (j < n - 1) dp[i][j] = min(dp[i][j], dp[i][j + 1] + 1);
                }
            }
        }
        
        // combining both
        return dp;
    }
};
/*
matrix[i][j] == 1:
dp[i][j] = min(dp[i - 1][j], dp[i][j - 1], dp[i + 1][j], dp[i][j + 1]) + 1;

matrix[i][j] == 0:
dp[i][j] = 0;

1 1 0      INF INF 0    2 1 0
1 1 1      INF INF 1    1 2 1
0 1 1       0   1  2    0 1 2
*/