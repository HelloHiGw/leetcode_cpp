class Solution {
public:
    int regionsBySlashes(vector<string>& grid) {
        vector<vector<int>> g(grid.size() * 3, vector<int>(grid.size() * 3, 0));
        for (int i = 0; i < grid.size(); ++i) {
            for (int j = 0; j < grid[0].size(); ++j) {
                if (grid[i][j] == '/') {
                    g[i * 3][j * 3 + 2] = g[i * 3 + 1][j * 3 + 1] = g[i * 3 + 2][j * 3] = 1; 
                } else if (grid[i][j] == '\\') {
                    g[i * 3][j * 3] = g[i * 3 + 1][j * 3 + 1] = g[i * 3 + 2][j * 3 + 2] = 1; 
                }
            }
        }
        
        vector<vector<int>> dirs = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
        int res = 0;        
        for (int i = 0; i < g.size(); ++i) {
            for (int j = 0; j < g[0].size(); ++j) {
                if (g[i][j] == 0) {
                    bfs(i, j, g, dirs);
                    ++res;
                }
            }
        }
        return res;
    }
    
private:
    void dfs(int i, int j, vector<vector<int>> &g, vector<vector<int>> &dirs) {
        if (i < 0 || i >= g.size() || j < 0 || j >= g[0].size() || g[i][j] == 1) return;
        g[i][j] = 1;
        for (auto &d : dirs) {
            dfs(i + d[0], j + d[1], g, dirs);
        }
    }

    bool judge(int i, int j, vector<vector<int>> &g) {
        return (i >= 0 && i < g.size() && j >= 0 && j < g[0].size() && g[i][j] == 0);
    }
    
    void bfs(int i, int j, vector<vector<int>> &g, vector<vector<int>> &dirs) {
        queue<pair<int, int>> q;
        q.push({i, j});
        g[i][j] = 1;
        while (!q.empty()) {
            i = q.front().first, j = q.front().second;
            q.pop();
            for (auto &d : dirs) {
                if (judge(i + d[0], j + d[1], g)) {
                    q.push({i + d[0], j + d[1]});
                    g[i + d[0]][j + d[1]] = 1;
                }
            }
        }
    }
};