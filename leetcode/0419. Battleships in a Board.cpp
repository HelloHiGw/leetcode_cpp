/*
you can use dfs to find connect blocks of board
that's the answer
*/

class Solution {
public:
    int countBattleships(vector<vector<char>>& board) {
        int res = 0;
        for (int i = 0; i < board.size(); ++i) {
            for (int j = 0; j < board[0].size(); ++j) {
                if (board[i][j] == 'X') {
                    if (i && board[i - 1][j] == 'X') continue;
                    if (j && board[i][j - 1] == 'X') continue;
                    ++res;
                }
            }
        }
        return res;
    }
};