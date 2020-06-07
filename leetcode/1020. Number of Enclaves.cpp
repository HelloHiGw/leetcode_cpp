class Solution {
public:
    int numEnclaves(vector<vector<int>>& A) {
        int m = A.size(), n = A[0].size();
        vector<vector<int>> dirs = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
        
        for (int i = 0; i < m; ++i) {
            if (A[i][0] == 1) bfs(i, 0, A, dirs);
            if (A[i][n - 1] == 1) bfs(i, n - 1, A, dirs);
        }
        for (int j = 0; j < n; ++j) {
            if (A[0][j] == 1) bfs(0, j, A, dirs);
            if (A[m - 1][j] == 1) bfs(m - 1, j, A, dirs);
        }
        
        int res = 0;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (A[i][j] == 1) ++res;
            }
        }
        return res;
    }
    
private:
    void dfs(int x, int y, vector<vector<int>>& A, vector<vector<int>>& dirs) {
        if (x < 0 || x == A.size() || y < 0 || y == A[0].size() || A[x][y] == 0) return;
        A[x][y] = 0;
        for (auto& d : dirs) {
            dfs(x + d[0], y + d[1], A, dirs);
        }
    }
    
    bool isValid(int x, int y, vector<vector<int>>& A) {
        return x >= 0 && x < A.size() && y >= 0 && y < A[0].size() && A[x][y] == 1;
    }
    
    void bfs(int x, int y, vector<vector<int>>& A, vector<vector<int>>& dirs) {
        A[x][y] = 0;
        queue<pair<int, int>> que;
        que.push({x, y});
        
        while (!que.empty()) {
            x = que.front().first, y = que.front().second;
            que.pop();
            for (auto& d : dirs) {
                int nx = x + d[0], ny = y + d[1];
                if (isValid(nx, ny, A)) {
                    A[nx][ny] = 0;
                    que.push({nx, ny});
                }
            }
        }
    }
};

