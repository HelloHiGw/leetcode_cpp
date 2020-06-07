class Solution {
public:
    bool validMountainArray(vector<int>& A) {
        if (A.size() < 3) return false;
        bool increasing = false, decreasing = false;
        for (int i = 1; i < A.size(); ++i) {
            if (A[i] == A[i - 1]) {
                return false;
            } else if (A[i] > A[i - 1]) {
                if (decreasing == true) return false;
                increasing = true;
            } else {
                if (increasing == false) return false;
                decreasing = true;
            }
        }
        return increasing && decreasing;
    }
};