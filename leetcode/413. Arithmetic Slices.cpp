// class Solution {
// public:
//     int numberOfArithmeticSlices(vector<int>& A) {
//         int n = A.size();
//         vector<int> dp(n, 0);  // dp[i] : arithmetic slice ending with A[i]
//         int res = 0;
//         for (int i = 2; i < n; ++i) {
//             if (A[i] - A[i - 1] == A[i - 1] - A[i - 2]) {  // common difference
//                 dp[i] = dp[i - 1] + 1;
//             }
//             res += dp[i];
//         }
//         return res;
//     }
// };

/*
At any index i, if we see it forms arith seq with former two, that means running (curr) 
sequence gets extended upto this index, at the same time we get one more sequence (the three 
numbers ending at i), so dp[i] = dp[i - 1](extended) + 1(new formed)
*/


class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& A) {
        int n = A.size();
        int curr = 0;
        int res = 0;
        for (int i = 2; i < n; ++i) {
            if (A[i] - A[i - 1] == A[i - 1] - A[i - 2]) {
                ++curr;
            } else {
                curr = 0;
            }
            res += curr;
        }
        return res;
    }
};