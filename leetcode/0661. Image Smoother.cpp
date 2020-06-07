class Solution {
public:
    vector<vector<int>> imageSmoother(vector<vector<int>>& M) {
        for (int i = 0; i < M.size(); ++i) {
            for (int j = 0; j < M[0].size(); ++j) {
                smooth(i, j, M);
            }
        }
        for (int i = 0; i < M.size(); ++i) {
            for (int j = 0; j < M[0].size(); ++j) {
                M[i][j] >>= 8;
            }
        }
        return M;
    }
  
    void smooth(int i, int j, vector<vector<int>>& M) {
        int sum = 0, cnt = 0;
        for (int r = i - 1; r <= i + 1; ++r) {
            for (int c = j - 1; c <= j + 1; ++c) {
                if (r >= 0 && r < M.size() && c >= 0 && c < M[0].size()) {
                    sum += M[r][c] % 256;
                    ++cnt;
                }
            }
        }
        int res = sum * 1.0 / cnt;
        M[i][j] = (res << 8) + M[i][j];
    }
};