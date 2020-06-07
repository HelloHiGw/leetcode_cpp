/*
put big vector out of class to avoid running out of memory ?
dfs + memo
time O (m * n * n * 9) states * cost
space O(m * n * n)

dp[r][c1][c2]
the maximum number of cherries collection using both robots 
putting at i = r, j1 = c1, j2 =c2
to collect cherries below r (including r)
*/

const int MAXN = 75;
int memo[MAXN][MAXN][MAXN];

class Solution {
public:
    int cherryPickup(vector<vector<int>>& grid) {
        memset(memo, -1, sizeof(memo));
        int m = grid.size(), n = grid[0].size();
        return dfs(grid, m, n, 0, 0, n - 1);
    }
    
private:
    int dfs(vector<vector<int>>& grid, int m, int n, int r, int c1, int c2) {
        if (r == m) return 0;
        if (memo[r][c1][c2] != -1) return memo[r][c1][c2];
        int res = 0;
        for (int i = -1; i <= 1; ++i) {
            for (int j = -1; j <= 1; ++j) {
                int nc1 = c1 + i, nc2 = c2 + j;
                if (nc1 >= 0 && nc1 < n && nc2 >= 0 && nc2 < n) {
                    res = max(res, dfs(grid, m, n, r + 1, nc1, nc2));
                }
            }
        }
        int curr = c1 == c2 ? grid[r][c1] : grid[r][c1] + grid[r][c2];
        return memo[r][c1][c2] = curr + res;
    }
};



/*
bottom up dp
time O (m * n * n * 9)
space O(m * n * n)
*/
const int MAXN = 75;
int dp[MAXN][MAXN][MAXN];

class Solution {
public:
    int cherryPickup(vector<vector<int>>& grid) {
        memset(dp, 0, sizeof(dp));
        int m = grid.size(), n = grid[0].size();
        
        for (int r = m - 1; r >= 0; --r) {
            for (int c1 = 0; c1 < n; ++c1) {
                for (int c2 = 0; c2 < n; ++c2) {
                    int curr = c1 == c2 ? grid[r][c1] : grid[r][c1] + grid[r][c2];
                    int next = 0;
                    for (int i = -1; i <= 1; ++i) {
                        for (int j = -1; j <= 1; ++j) {
                            int nc1 = c1 + i, nc2 = c2 + j;
                            if (nc1 < 0 || nc1 >= n || nc2 < 0 || nc2 >= n) continue;
                            next = max(next, dp[r + 1][c1 + i][c2 + j]);
                        }
                    }
                    dp[r][c1][c2] = next + curr;
                }
            }
        }
        
        return dp[0][0][n - 1];
    }
};