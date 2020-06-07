class Solution {
public:
    string tictactoe(vector<vector<int>>& moves) {
        vector<vector<int>> row(2, vector<int>(3)), col(2, vector<int>(3));
        vector<int> d1(2), d2(2);
        for (int i = 0; i < moves.size(); ++i) {
            int id = i % 2;
            int r = moves[i][0], c = moves[i][1];
            if (++row[id][r] == 3 || ++col[id][c] == 3 || (r == c && ++d1[id] == 3) || (r + c == 2 && ++d2[id] == 3)) {
                return id == 0 ? "A" : "B";
            }
        }
        return moves.size() == 9 ? "Draw" : "Pending";
    }
};