class Solution {
public:
    vector<int> sortedSquares(vector<int>& A) {
        vector<int> res(A.size());
        int i = 0, j = A.size() - 1, idx = A.size() - 1;
        while (i <= j) {
            if (abs(A[i]) > abs(A[j])) {
                res[idx--] = A[i] * A[i];
                ++i;
            } else {
                res[idx--] = A[j] * A[j];
                --j;
            }
        }
        return res;
    }
};