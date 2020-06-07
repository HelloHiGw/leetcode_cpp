// class Solution {
// public:
//     int rotatedDigits(int N) {
//         int res = 0;
//         for (int i = 1; i <= N; ++i) {
//             int n = i;
//             bool valid = false, invalid = false;
//             while (n) {
//                 int d = n % 10;
//                 if (isInvalid(d)) {
//                     invalid = true;
//                     break;
//                 }
//                 if (isValid(d)) valid = true;
//                 n /= 10;
//             }
//             if (valid && !invalid) ++res;
//         }
//         return res;
//     }
    
//     bool isValid(int n) {
//         return n == 2 || n == 5 || n == 6 || n ==9;
//     }
    
//     bool isInvalid(int n) {
//         return n == 3 || n == 4 || n == 7;
//     }
// };


class Solution {
public:
    int rotatedDigits(int N) {
        int res = 0;
        vector<int> dp(N + 1);  // 0 invalid, 1 the same, 2 valid
        for (int i = 0; i <= N; ++i) {
            if (i < 10) {
                if (i == 0 || i == 1 || i == 8) {
                    dp[i] = 1;
                } else if (i == 2 || i == 5 || i == 6 || i == 9) {
                    dp[i] = 2;
                    ++res;
                }
            } else {
                int a = dp[i / 10], b = dp[i % 10];
                if (a == 1 && b == 1) {
                    dp[i] = 1;
                } else if (a >= 1 && b >= 1) {
                    dp[i] = 2;
                    ++res;
                }
            }
        }
        return res;
    }
};