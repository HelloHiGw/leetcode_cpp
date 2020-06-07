// dfs with memorization 
class Solution {
public:
    int findPaths(int m, int n, int N, int i, int j) {
        vector<vector<int>> dirs = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
        vector<vector<vector<int>>> memo (N + 1, vector<vector<int>>(m, vector<int>(n, -1)));
        return dfs(i, j, m, n, N, dirs, memo);
    }

private:
    const int MOD = 1e9 + 7;
    
    int dfs(int x, int y, int m, int n, int N, vector<vector<int>>& dirs, vector<vector<vector<int>>>& memo) {
        if (x < 0 || x == m || y < 0 || y == n) return 1;
        if (N == 0) return 0;
        if (memo[N][x][y] != -1) return memo[N][x][y];
        
        int count = 0;
        for (const auto& d : dirs) {
            count = (count + dfs(x + d[0], y + d[1], m, n, N - 1, dirs, memo)) % MOD;
        }
        return memo[N][x][y] = count;
    }
};


// iterative dp
class Solution {
public:
    int findPaths(int m, int n, int N, int i, int j) {
        vector<vector<vector<int>>> dp(N + 1, vector<vector<int>>(m, vector<int>(n, 0)));
        const int MOD = 1e9 + 7;
        
        for (int s = 1; s <= N; ++s) { // steps
            for (int x = 0; x < m; ++x) {
                for (int y = 0; y < n; ++y) {
                    dp[s][x][y] = ((x == 0 ? 1 : dp[s - 1][x - 1][y]) + dp[s][x][y]) % MOD;
                    dp[s][x][y] = ((x == m - 1 ? 1 : dp[s - 1][x + 1][y]) + dp[s][x][y]) % MOD;
                    dp[s][x][y] = ((y == 0 ? 1 : dp[s - 1][x][y - 1]) + dp[s][x][y]) % MOD;
                    dp[s][x][y] = ((y == n - 1 ? 1 : dp[s - 1][x][y + 1]) + dp[s][x][y]) % MOD;
                }
            }
        }
        return dp[N][i][j];
    }
};


class Solution {
public:
    int findPaths(int m, int n, int N, int i, int j) {
        vector<vector<int>> curr(m, vector<int>(n, 0));
        vector<vector<int>> prev(m, vector<int>(n, 0));
        const int MOD = 1e9 + 7;
        
        for (int s = 1; s <= N; ++s) { // steps
            for (int x = 0; x < m; ++x) {
                for (int y = 0; y < n; ++y) {
                    curr[x][y] = 0;
                    curr[x][y] = ((x == 0 ? 1 : prev[x - 1][y]) + curr[x][y]) % MOD;
                    curr[x][y] = ((x == m - 1 ? 1 : prev[x + 1][y]) + curr[x][y]) % MOD;
                    curr[x][y] = ((y == 0 ? 1 : prev[x][y - 1]) + curr[x][y]) % MOD;
                    curr[x][y] = ((y == n - 1 ? 1 : prev[x][y + 1]) + curr[x][y]) % MOD;
                }
            }
            swap(prev, curr);
        }
        return prev[i][j];
    }
};