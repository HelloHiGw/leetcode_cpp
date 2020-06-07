 // Flood from the ocean! 
class Solution {
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& matrix) {
        if (matrix.empty() || matrix[0].empty()) return {};
        int m = matrix.size(), n = matrix[0].size();
        vector<vector<bool>> pacific(m, vector<bool>(n, false));
        vector<vector<bool>> atlantic(m, vector<bool>(n, false));
        vector<vector<int>> dirs = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
        
        for (int i = 0; i < m; ++i) {
            // dfs(i, 0, -1, matrix, pacific, dirs);
            // dfs(i, n - 1, -1, matrix, atlantic, dirs);
            bfs(i, 0, matrix, pacific, dirs);
            bfs(i, n - 1, matrix, atlantic, dirs);          
        }
        for (int j = 0; j < n; ++j) {
            // dfs(0, j, -1, matrix, pacific, dirs);
            // dfs(m - 1, j, -1, matrix, atlantic, dirs);
            bfs(0, j, matrix, pacific, dirs);
            bfs(m - 1, j, matrix, atlantic, dirs);
        }
        
        vector<vector<int>> res;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (pacific[i][j] && atlantic[i][j]) res.push_back({i, j});
            }
        }
        return res;
    }
    
private:
    void dfs(int x, int y, int height, vector<vector<int>> &matrix, vector<vector<bool>> &visited, vector<vector<int>> &dirs) {
        if (x < 0 || x == matrix.size() || y < 0 || y == matrix[0].size() || matrix[x][y] < height || visited[x][y]) return;
        visited[x][y] = true;
        for (auto &d : dirs) {
            dfs(x + d[0], y + d[1], matrix[x][y], matrix, visited, dirs);
        }
        
    }

    bool isValid(int x, int y, int height, vector<vector<int>> &matrix, vector<vector<bool>> &visited) {
        return x >= 0 && x < matrix.size() && y >= 0 && y < matrix[0].size() && matrix[x][y] >= height && !visited[x][y];
    }
    
    void bfs(int x, int y, vector<vector<int>> &matrix, vector<vector<bool>> &visited, vector<vector<int>> &dirs) {
        queue<pair<int, int>> que;
        que.push({x, y});
        visited[x][y] = true;
        
        while (!que.empty()) {
            x = que.front().first, y = que.front().second;
            que.pop();
            for (auto &d : dirs) {
                int nx = x + d[0], ny = y + d[1];
                if (isValid(nx, ny, matrix[x][y], matrix, visited)) {
                    que.push({nx, ny});
                    visited[nx][ny] = true;
                }
            }
        }
    }
};

