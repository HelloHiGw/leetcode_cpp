class Solution {
public:
    int minDeletionSize(vector<string>& A) {
        if (A.empty() || A[0].empty()) return 0;
        int res = 0;
        for (int i = 0; i < A[0].size(); ++i) {
            for (int j = 1; j < A.size(); ++j) {
                if (A[j][i] < A[j - 1][i]) {
                    ++res;
                    break;
                }
            }
        }
        return res;
    }
};