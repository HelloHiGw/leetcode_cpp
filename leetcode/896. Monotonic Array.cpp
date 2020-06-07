class Solution {
public:
    bool isMonotonic(vector<int>& A) {
        bool increasing = false;
        bool decreasing = false;
        for (int i = 1; i < A.size(); ++i) {
            if (A[i] > A[i - 1]) {
                increasing = true;
            } else if (A[i] < A[i - 1]) {
                decreasing = true;
            }
            if (increasing && decreasing) return false;
        }
        return true;
    }
};