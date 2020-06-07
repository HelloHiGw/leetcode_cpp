// // O(knnn) getChanges need O(n)
// class Solution {
// public:
//     int palindromePartition(string s, int k) {
//         int n = s.size();
//         const int INF = 0x3fffffff;
//         vector<vector<int>> dp(k + 1, vector<int>(n + 1, INF));
//         dp[0][0] = 0;
//         for (int i = 1; i <= k; ++i) {
//             for (int j = i; j <= n; ++j) {
//                 for (int k = i - 1; k < j; ++k) {
//                     int count = getChanges(s, k, j - 1);
//                     dp[i][j] = min(dp[i][j], dp[i - 1][k] + count);
//                 }
//             }
//         }
//         return dp[k][n];
//     }
    
// private:
//     /*
//     return count of chars changed to make it palindrome
//     */
//     int getChanges(string& s, int low, int high) {
//         int count = 0;
//         while (low < high) {
//             if (s[low] != s[high]) ++count;
//             ++low;
//             --high;
//         }
//         return count;
//     }
// };


// // time complexity O(knn)  space complexity O(n^2)
// class Solution {
// public:
//     int palindromePartition(string s, int k) {
//         int n = s.size();
//         vector<vector<int>> cost(n, vector<int>(n, 0));  // changes needed to make [indexI, indexJ] to palindrome (i <= j) cost[i][i] = 0
        
//         for (int l = 2; l <= n; ++l) {
//             for (int i = 0, j = l - 1; j < n; ++i, ++j) {
//                 cost[i][j] = cost[i + 1][j - 1] + (s[i] != s[j]);
//             }
//         }
        
//         const int INF = 0x3fffffff;
//         vector<vector<int>> dp(k + 1, vector<int>(n + 1, INF));
//         dp[0][0] = 0;
//         for (int i = 1; i <= k; ++i) {
//             for (int j = i; j <= n; ++j) {
//                 for (int k = i - 1; k < j; ++k) {
//                     int count = cost[k][j - 1];
//                     dp[i][j] = min(dp[i][j], dp[i - 1][k] + count);
//                 }
//             }
//         }
//         return dp[k][n];
//     }
// };


//  time complexity O(knn)  space complexity O(n^2)
class Solution {
public:
    int palindromePartition(string s, int k) {
        int n = s.size();
        vector<vector<int>> cost(n, vector<int>(n, 0));  // changes needed to make [indexI, indexJ] to palindrome (i <= j) cost[i][i] = 0
        
        for (int l = 2; l <= n; ++l) {
            for (int i = 0, j = l - 1; j < n; ++i, ++j) {
                cost[i][j] = cost[i + 1][j - 1] + (s[i] != s[j]);
            }
        }
        
        const int INF = 0x3fffffff;
        vector<int> dp(n + 1, INF);
        dp[0] = 0;
        for (int i = 1; i <= k; ++i) {
            for (int j = n; j >= i; --j) {
                dp[j] = INF;
                for (int k = i - 1; k < j; ++k) {
                    int count = cost[k][j - 1];
                    dp[j] = min(dp[j], dp[k] + count);
                }
            }
        }
        return dp[n];
    }
};