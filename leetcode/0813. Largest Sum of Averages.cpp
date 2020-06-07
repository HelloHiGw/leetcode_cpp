// class Solution {
// public:
//     double largestSumOfAverages(vector<int>& A, int K) {
//         int n = A.size();
//         vector<vector<double>> dp(K + 1, vector<double>(n + 1, INT_MIN));  // INT_MIN is difficult to understand, we want max, so set min as initialization
//         dp[0][0] = 0;
//         for (int i = 1; i <= K; ++i) {
//             for (int j = i; j <= n; ++j) {  // at least i numbers if you want partition i groups
//                 double sum = 0, average = 0;
//                 for (int p = j - 1; p >= i - 1; --p) {
//                     sum += A[p];  // j - 1 + 1 - 1 (+1 next) (-1 A is 0-based)
//                     average = sum / (j - p);
//                     dp[i][j] = max(dp[i][j], dp[i - 1][p] + average);
//                 }
//             }
//         }
//         return dp[K][n];
//     }
// };

/*
dp[i][j] denotes largest sum of averages of j numbers partioned into i groups

initialization
dp[0][0] = 0   dp[*][*] = INT_MIN  
INT_MIN (< 0) denotes there is no answer
INT_MIN + positiveInteger < 0, that means partition into i - 1 groups, no answer, so partition into i groups, no answer
-1 + positiveInteger may be > 0, that means partition into i - 1 groups, no answer, but partition into i groups, there is an answer, which is incorrect

transition
dp[i][j] = max(dp[i - 1][k] + average(A[k + 1], ..., ... A[j]))  k + 1 denotes the (k + 1)th element
i - 1 <= k < j
there must be at least one element in the ith group, i.e k < j (you can not arrange j numbers in i-1 groups, and ith group empty)
there must be at least i - 1 elements in i - 1 groups, otherwise it cannot be partitioned into i - 1 groups


you need to be carefully when calculating dp[1][j] (only happens when groups = 1)
1 3 5
dp[1][3] = dp[0][2] + 5 / 1       dp[0][1] + 8 / 2      dp[0][0] + 9 / 3 = 3
if you set dp[*][*] = -1 as initialization, dp[0][2] + 5 / 1 = 4
so dp[1][3] = 4, which is incorrect

time complexity O(Knn) space complexity O(Kn)

[9, 1, 2, 3, 9]  K = 3

               j = 1      j = 2      j = 3      j = 4       j = 5      

i = 1          9          5          4          3.75        4.8

i = 2                     9 + 1/1    5 + 2/1    4 + 3/1     3.75 + 9/1
                          (10)       9 + 3/2    5 + 5/2     4 + 12/2
                                     (10.5)     9 + 6/3     5 + 14/3
                                                (11)        9 + 15/4
                                                            (12.75)

i = 3                                10 + 2/1   10.5 + 3/1  11 + 9/1
                                     (12)       10 + 5/2    10.5 + 12/2
                                                (13.5)      10 + 14/3
                                                            (20)

*/


class Solution {
public:
    double largestSumOfAverages(vector<int>& A, int K) {
        int n = A.size();
        vector<double> dp(n + 1, INT_MIN);  
        dp[0] = 0;
        for (int i = 1; i <= K; ++i) {
            for (int j = n; j >= i; --j) {  // need dp[i - 1][j - *] so we enumerate from right to left
                dp[j] = INT_MIN;  // no answer, initialization for every i
                double sum = 0, average = 0;
                for (int p = j - 1; p >= i - 1; --p) {
                    sum += A[p];
                    average = sum / (j - p);
                    dp[j] = max(dp[j], dp[p] + average);
                }
            }
        }
        return dp[n];
    }
};