class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        vector<vector<int>> dirs = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
        int res = 0;
        for (int i = 0; i < grid.size(); ++i) {
            for (int j = 0; j < grid[0].size(); ++j) {
                if (grid[i][j] == 1) {
                    res = max(res, bfs(i, j, grid, dirs));
                }
            }
        }
        return res;
    }
    
private:
    int dfs(int x, int y, vector<vector<int>>& grid, vector<vector<int>>& dirs) {
        if (x < 0 || x == grid.size() || y < 0 || y == grid[0].size() || grid[x][y] != 1) return 0;
        grid[x][y] = 2;  // visited
        int count = 1;
        for (auto& d : dirs) {
            count += dfs(x + d[0], y + d[1], grid, dirs);
        }
        return count;
    }
    
    bool isValid(int x, int y, vector<vector<int>>& grid) {
        return x >= 0 && x < grid.size() && y >= 0 && y < grid[0].size() && grid[x][y] == 1;
    }
    
    int bfs(int x, int y, vector<vector<int>>& grid, vector<vector<int>>& dirs) {
        queue<pair<int, int>> que;
        que.push({x, y});
        grid[x][y] = 2;
        int count = 0;
        
        while (!que.empty()) {
            x = que.front().first, y = que.front().second;
            que.pop();
            ++count;
            for (auto& d : dirs) {
                int nx = x + d[0], ny = y + d[1];
                if (isValid(nx, ny, grid)) {
                    que.push({nx, ny});
                    grid[nx][ny] = 2;
                }
            }
        }
        return count;
    }
};

