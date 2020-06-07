// class Solution {
// public:
//     string longestPalindrome(string s) {
//         if (s.size() < 2) return s;
//         int start = 0, maxLen = 1;
//         for (int i = 0; i < s.size(); ++i) {
//             searchPalindrome(s, i, i, start, maxLen);
//             searchPalindrome(s, i, i + 1, start, maxLen);
//         }
//         return s.substr(start, maxLen);
//     }
    
//     void searchPalindrome(string s, int i, int j, int &start, int &maxLen) {
//         while (i >= 0 && j < s.size() && s[i] == s[j]) {
//             --i;
//             ++j;
//         }
//         int len =  (j - 1) - (i + 1) + 1;  // current i and j are unmatched
//         if (len > maxLen) {
//             maxLen = len;
//             start = i + 1;
//         }
//     }
// };


class Solution {
public:
    string longestPalindrome(string s) {
        if (s.empty()) return "";
        int start = 0, maxLen = 1, n = s.size();
        vector<vector<bool>> dp(n, vector<bool>(n, false));
        for (int i = n - 1; i >= 0; --i) {  // needs dp[i + 1][], so we enumerate from right to left
            for (int j = i; j < n; ++j) {
                if (j == i || j == i + 1) {  // base case
                    dp[i][j] = s[i] == s[j];
                } else {
                    dp[i][j] = (s[i] == s[j]) && dp[i + 1][j - 1];
                }

                if (dp[i][j] && (j - i + 1) > maxLen) {
                    start = i;
                    maxLen = j - i + 1;
                }
            }
        }
        return s.substr(start, maxLen);
    }
};


class Solution {
public:
    string longestPalindrome(string s) {
        if (s.empty()) return "";
        int start = 0, maxLen = 1, n = s.size();
        vector<vector<bool>> dp(n, vector<bool>(n, false));
        for (int j = 0; j < n; ++j) {   // enumerate j first
            for (int i = 0; i <= j; ++i) {
                if (j == i || j == i + 1) { 
                    dp[i][j] = s[i] == s[j];
                } else {
                    dp[i][j] = (s[i] == s[j]) && dp[i + 1][j - 1];
                }

                if (dp[i][j] && (j - i + 1) > maxLen) {
                    start = i;
                    maxLen = j - i + 1;
                }
            }
        }
        return s.substr(start, maxLen);
    }
};


class Solution {
public:
    string longestPalindrome(string s) {
        if (s.empty()) return "";
        int start = 0, maxLen = 1, n = s.size();
        vector<vector<bool>> dp(n, vector<bool>(n, false));
        
        for (int i = 0; i < n; ++i) {
            dp[i][i] = true;
            if (i < n - 1 && s[i] == s[i + 1]) {
                dp[i][i + 1] = true;
                start = i;
                maxLen = 2;
            }
        }
        
        for (int l = 3; l <= n; ++l) {
            for (int i = 0, j = l - 1; j < n; ++i, ++j) {
                // the length of dp[i + 1][j - 1] is smaller than dp[i][j]
                // as we enumerate l from small to big, so dp[i + 1][j - 1] must have been calculated
                dp[i][j] = (s[i] == s[j]) && dp[i + 1][j - 1];
                
                if (dp[i][j] && l > maxLen) {
                    start = i;
                    maxLen = l;
                }
            }
        }
        
        return s.substr(start, maxLen);
    }
};



