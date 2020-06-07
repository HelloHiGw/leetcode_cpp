class Solution {
public:
    double knightProbability(int N, int K, int r, int c) {
        vector<vector<int>> dirs = {{-2, 1}, {-1, 2}, {1, 2}, {2, 1}, {2, -1}, {1, -2}, {-1, -2}, {-2, -1}};
        vector<vector<vector<double>>> memo(K + 1, vector<vector<double>>(N, vector<double>(N, -1)));
        return dfs(N, K, r, c, dirs, memo);
    }
    
private:
    double dfs(int N, int K, int r, int c, vector<vector<int>>& dirs, vector<vector<vector<double>>>& memo) {
        // not r == N, c == N, r and c may be bigger than N (can forward 2 steps a time)
        if (r < 0 || r >= N || c < 0 || c >= N) return 0;
        if (K == 0) return 1;
        if (memo[K][r][c] != -1) return memo[K][r][c];
        double rate = 0;
        for (auto& d : dirs) {
            rate += 0.125 * dfs(N, K - 1, r + d[0], c + d[1], dirs, memo);
        }
        return memo[K][r][c] = rate;
    }
};


class Solution {
public:
    double knightProbability(int N, int K, int r, int c) {
        vector<vector<int>> dirs = {{-2, 1}, {-1, 2}, {1, 2}, {2, 1}, {2, -1}, {1, -2}, {-1, -2}, {-2, -1}};
        vector<vector<vector<double>>> dp(K + 1, vector<vector<double>>(N, vector<double>(N, 0)));
        
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < N; ++j) {
                dp[0][i][j] = 1;
            }
        }
        
        for (int k = 1; k <= K; ++k) {
            for (int i = 0; i < N; ++i) {
                for (int j = 0; j < N; ++j) {
                    for (auto& d : dirs) {
                        int ni = i + d[0], nj = j + d[1];
                        if (ni >= 0 && ni < N && nj >= 0 && nj < N) {
                            dp[k][i][j] += 0.125 * dp[k - 1][ni][nj];
                        }
                    }
                }
            }
        }
        
        return dp[K][r][c];
    }
};



class Solution {
public:
    double knightProbability(int N, int K, int r, int c) {
        vector<vector<int>> dirs = {{-2, 1}, {-1, 2}, {1, 2}, {2, 1}, {2, -1}, {1, -2}, {-1, -2}, {-2, -1}};
        vector<vector<double>> prev(N, vector<double>(N, 0)), curr(N, vector<double>(N, 0));
        
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < N; ++j) {
                prev[i][j] = 1;
            }
        }
        
        for (int k = 1; k <= K; ++k) {
            for (int i = 0; i < N; ++i) {
                for (int j = 0; j < N; ++j) {
                    curr[i][j] = 0;
                    for (auto& d : dirs) {
                        int ni = i + d[0], nj = j + d[1];
                        if (ni >= 0 && ni < N && nj >= 0 && nj < N) {
                            curr[i][j] += 0.125 * prev[ni][nj];
                        }
                    }
                }
            }
            swap(prev, curr);
        }
        
        return prev[r][c];
    }
};