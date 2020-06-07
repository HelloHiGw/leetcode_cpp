// set invalid 'O' to '*'
// then set remaining(valid) 'O' to 'X', '*' to 'O'
class Solution {
public:
    void solve(vector<vector<char>>& board) {
        if (board.empty() || board[0].empty()) return;
        vector<vector<int>> dirs = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
        int numRows = board.size(), numCols = board[0].size();
        
        for (int i = 0; i < numRows; ++i) {
            if (board[i][0] == 'O') bfs(i, 0, board, dirs);
            if (board[i][numCols - 1] == 'O') bfs(i, numCols - 1, board, dirs);
        }
        for (int j = 0; j < numCols; ++j) {
            if (board[0][j] == 'O') bfs(0, j, board, dirs);
            if (board[numRows - 1][j] == 'O') bfs(numRows - 1, j, board, dirs);
        }
        
        for (int i = 0; i < numRows; ++i) {
            for (int j = 0; j < numCols; ++j) {
                if (board[i][j] == 'O') {
                    board[i][j] = 'X';
                } else if (board[i][j] == '*') {
                    board[i][j] = 'O';
                }
            }
        }
    }
    
private:
    void dfs(int x, int y, vector<vector<char>> &board, vector<vector<int>> &dirs) {
        if (x < 0 || x == board.size() || y < 0 || y == board[0].size() || board[x][y] != 'O') return;
        board[x][y] = '*';
        for (auto &d : dirs) {
            dfs(x + d[0], y + d[1], board, dirs);
        }
    }

    bool isValid(int x, int y, vector<vector<char>> &board) {
        return x >= 0 && x < board.size() && y >= 0 && y < board[0].size() && board[x][y] == 'O';
    }
    
    void bfs(int x, int y, vector<vector<char>> &board, vector<vector<int>> &dirs) {
        queue<pair<int, int>> que;
        que.push({x, y});
        board[x][y] = '*';
        
        while (!que.empty()) {
            x = que.front().first, y = que.front().second;
            que.pop();
            for (auto &d : dirs) {
                int nx = x + d[0], ny = y + d[1];
                if (isValid(nx, ny, board)) {
                    que.push({nx, ny});
                    board[nx][ny] = '*';
                }
            }
        }
    }
};