/*
the key is to find the longest palindromic subsequence
then the answer is n - Length
so it converts to 516. Longest Palindromic Subsequence
*/


/*
using the idea of Longest Palindrome

but here is subsequence, we need to inherit when mismatch

time O(n * n)
space O(n * n)
*/
class Solution {
public:
    int minInsertions(string s) {
        int n = s.size();
        vector<vector<int>> dp(n, vector<int>(n));
        
        for (int i = n - 1; i >= 0; --i) {
            dp[i][i] = 1;
            for (int j = i + 1; j < n; ++j) {
                if (s[i] == s[j]) {
                    dp[i][j] = dp[i + 1][j - 1] + 2;
                } else {
                    dp[i][j] = max(dp[i + 1][j], dp[i][j - 1]);
                }
            }
        }
        
        return n - dp[0][n - 1];
    }
};


/*
same as above, but enumerate by len
*/
class Solution {
public:
    int minInsertions(string s) {
        int n = s.size();
        vector<vector<int>> dp(n, vector<int>(n));
        
        for (int i = 0; i < n; ++i) dp[i][i] = 1;
        
        for (int l = 2; l <= n; ++l) {
            for (int i = 0, j = l - 1; j < n; ++i, ++j) {
                if (s[i] == s[j]) {
                    dp[i][j] = dp[i + 1][j - 1] + 2;
                } else {
                    dp[i][j] = max(dp[i + 1][j], dp[i][j - 1]);
                }
            }
        }
        
        return n - dp[0][n - 1];
    }
};


/*
using LCS of s and reversed s
time O(n * n)
space O(n * n)
*/
class Solution {
public:
    int minInsertions(string s) {
        string s2(s.rbegin(), s.rend());
        int n = s.size();
        vector<vector<int>> dp(n + 1, vector<int>(n + 1));
        
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= n; ++j) {
                if (s[i - 1] == s2[j - 1]) {
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                } else {
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                }
            }
        }
        
        return n - dp[n][n];
    }
};