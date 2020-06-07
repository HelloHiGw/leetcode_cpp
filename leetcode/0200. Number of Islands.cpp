class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        vector<vector<int>> dirs = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
        int res = 0;
        for (int i = 0; i < grid.size(); ++i) {
            for (int j = 0; j < grid[0].size(); ++j) {
                if (grid[i][j] == '1') {
                    bfs(i, j, grid, dirs);
                    ++res;
                }
            }
        }
        return res;
    }
    
private:
    void dfs(int i, int j, vector<vector<char>> &grid, vector<vector<int>> &dirs) {
        if (i < 0 || i >= grid.size() || j < 0 || j >= grid[0].size() || grid[i][j] == '0') return;
        grid[i][j] = '0';
        for (auto &d : dirs) {
            dfs(i + d[0], j + d[1], grid, dirs);
        }
    }
    
    bool judge(int i, int j, vector<vector<char>> &grid) {
        return (i >= 0 && i < grid.size() && j >= 0 && j < grid[0].size() && grid[i][j] == '1');
    }
    
    void bfs(int i, int j, vector<vector<char>> &grid, vector<vector<int>> &dirs) {
        queue<pair<int, int>> q;
        q.push({i, j});
        grid[i][j] = '0';
        while (!q.empty()) {
            i = q.front().first, j = q.front().second;
            q.pop();
            for (auto &d : dirs) {
                if (judge(i + d[0], j + d[1], grid)) {
                    q.push({i + d[0], j + d[1]});
                    grid[i + d[0]][j + d[1]] = '0';
                }
            }
        }
    }
};

