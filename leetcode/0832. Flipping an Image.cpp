class Solution {
public:
    vector<vector<int>> flipAndInvertImage(vector<vector<int>>& A) {
        for (int i = 0; i < A.size(); ++i) {
            for (int m = 0, n = A[0].size() - 1; m <= n; ++m, --n) {
                if (A[i][m] == A[i][n]) {
                    A[i][m] ^= 1;
                    A[i][n] = A[i][m];
                }
            }
        }
        return A;
    }
};