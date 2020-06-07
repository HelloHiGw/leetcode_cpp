class Solution {
public:
    vector<vector<char>> updateBoard(vector<vector<char>>& board, vector<int>& click) {
        int i = click[0], j = click[1];
        if (board[i][j] == 'M') {
            board[i][j] = 'X';
            return board;
        }
        bfs(i, j, board);
        return board;
    }
    
private:
    int getAdjMines(int x, int y, vector<vector<char>>& board) {
        int count = 0;
        for (int dx = -1; dx <= 1; ++dx) {
            for (int dy = -1; dy <= 1; ++dy) {
                int nx = x + dx, ny = y + dy;
                if (nx >= 0 && nx < board.size() && ny >= 0 && ny < board[0].size() && board[nx][ny] == 'M') ++count;
            }
        }
        return count;
    }
    
    void dfs(int x, int y, vector<vector<char>>& board) {
        if (x < 0 || x == board.size() || y < 0 || y == board[0].size() || board[x][y] != 'E') return;
        int count = getAdjMines(x, y, board);
        if (count) {
            board[x][y] = count + '0';
            return;
        }
        board[x][y] = 'B';
        for (int dx = -1; dx <= 1; ++dx) {
            for (int dy = -1; dy <= 1; ++dy) {
                dfs(x + dx, y + dy, board);
            }
        }
    }
    
    bool isValid(int x, int y, vector<vector<char>>& board) {
        return x >= 0 && x < board.size() && y >= 0 && y < board[0].size() && board[x][y] == 'E';
    }
    
    void bfs(int x, int y, vector<vector<char>>& board) {
        queue<pair<int, int>> que;
        que.push({x, y});
        board[x][y] = 'B';
        
        while (!que.empty()) {
            x = que.front().first, y = que.front().second;
            que.pop();
            int count = getAdjMines(x, y, board);
            if (count) {
                board[x][y] = count + '0';
                continue;
            }

            for (int dx = -1; dx <= 1; ++dx) {
                for (int dy = -1; dy <= 1; ++dy) {
                    int nx = x + dx, ny = y + dy;
                    if (isValid(nx, ny, board)) {
                        que.push({nx, ny});
                        board[nx][ny] = 'B';
                    }
                }
            }
        }
    }
    
};