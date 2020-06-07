// class Solution {
// public:
//     bool exist(vector<vector<char>>& board, string word) {
//         vector<vector<bool>> visited(board.size(), vector<bool>(board[0].size(), false));
//         vector<vector<int>> dirs = {{-1, 0}, {1, 0}, {0, - 1}, {0, 1}};
//         for (int i = 0; i < board.size(); ++i) {
//             for (int j = 0; j < board[0].size(); ++j) {
//                 if (backtrack(i, j, board, dirs, visited, word, 0)) return true;
//             }
//         }
//         return false;
//     }
    
//     bool backtrack(int i, int j, vector<vector<char>>& board, vector<vector<int>>& dirs, vector<vector<bool>>& visited, string& word, int index) {
//         if (index == word.size()) {
//             return true;
//         }
//         if (i < 0 || i == board.size() || j < 0 || j == board[0].size()) return false;
//         if (visited[i][j] || board[i][j] != word[index]) return false;
//         visited[i][j] = true;
//         for (int k = 0; k < dirs.size(); ++k) {
//             bool find = backtrack(i + dirs[k][0], j + dirs[k][1], board, dirs, visited, word, index + 1);
//             if (find) return true;
//         }
//         visited[i][j] = false;
//         return false;
//     }
// };


class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        vector<vector<int>> dirs = {{-1, 0}, {1, 0}, {0, - 1}, {0, 1}};
        for (int i = 0; i < board.size(); ++i) {
            for (int j = 0; j < board[0].size(); ++j) {
                if (backtrack(i, j, board, dirs, word, 0)) return true;
            }
        }
        return false;
    }
    
    bool backtrack(int i, int j, vector<vector<char>>& board, vector<vector<int>>& dirs, string& word, int index) {
        if (index == word.size()) {
            return true;
        }
        if (i < 0 || i == board.size() || j < 0 || j == board[0].size()) return false;
        if (board[i][j] != word[index]) return false;
        char ch = board[i][j];  // set board[i][j] = '*' as visited
        board[i][j] = '*';
        for (int k = 0; k < dirs.size(); ++k) {
            bool find = backtrack(i + dirs[k][0], j + dirs[k][1], board, dirs, word, index + 1);
            if (find) return true;
        }
        board[i][j] = ch;
        return false;
    }
};