// class Solution {
// public:
//     int fib(int N) {
//         if (N < 2) return N;
//         return fib(N - 1) + fib(N - 2);
//     }
// };

// class Solution {
// public:
//     int fib(int N) {
//         if (N < 2) return N;
//         vector<int> dp(N + 1);
//         return fibNum(N, dp);
//     }
    
//     int fibNum(int N, vector<int>& dp) {
//         if (N < 2) return N;
//         if (dp[N] != 0) return dp[N];
//         return dp[N] = fibNum(N - 1, dp) + fibNum(N - 2, dp);
//     }
// };

// class Solution {
// public:
//     int fib(int N) {
//         if (N < 2) return N;
//         vector<int> dp(N + 1);
//         dp[1] = 1;
//         for (int i = 2; i <= N; ++i) {
//             dp[i] = dp[i - 1] + dp[i - 2];
//         }
//         return dp[N];
//     }
// };

class Solution {
public:
    int fib(int N) {
        if (N < 2) return N;
        int a = 0, b = 1, c = 1;
        for (int i = 2; i <= N; ++i) {
            c = a + b;
            a = b;
            b = c;
        }
        return c;
    }
};