/*
time O(m * n) , maybe more, there are string concatenation time
space O(m * n * O(string))
*/
class Solution {
public:
    string shortestCommonSupersequence(string str1, string str2) {
        int m = str1.size(), n = str2.size();
        vector<vector<string>> dp(m + 1, vector<string>(n + 1));
        
        // get the LCS (string) of str1 and str2
        for (int i = 1; i <= m; ++i) {
            for (int j = 1; j <= n; ++j) {
                if (str1[i - 1] == str2[j - 1]) {
                    dp[i][j] = dp[i - 1][j - 1] + str1[i - 1];
                } else {
                    dp[i][j] = dp[i - 1][j].size() > dp[i][j - 1].size() ? dp[i - 1][j] : dp[i][j - 1];
                }
            }
        }
        
        string LCS = dp[m][n];        
        string res;
        int i = 0, j = 0;
        for (char ch : LCS) {
            while (str1[i] != ch) res += str1[i++];
            while (str2[j] != ch) res += str2[j++];
            res +=ch;
            ++i;
            ++j;
        }
        res += str1.substr(i) + str2.substr(j);
        
        return res;
    }
    
};


/*
time O(m * n)
space O(m * n
*/
class Solution {
public:
    string shortestCommonSupersequence(string str1, string str2) {
        int m = str1.size(), n = str2.size();
        vector<vector<int>> dp(m + 1, vector<int>(n + 1));
        
        // get the LCS (length) of str1 and str2
        for (int i = 1; i <= m; ++i) {
            for (int j = 1; j <= n; ++j) {
                if (str1[i - 1] == str2[j - 1]) {
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                } else {
                    dp[i][j] = max(dp[i][j - 1], dp[i - 1][j]);
                }
            }
        }
        
        string res;
        for (int i = m, j = n; i > 0 || j > 0;) {
            if (i > 0 && dp[i][j] == dp[i - 1][j]) {  // it denotes str1[i - 1] not belongs to LCS, we need to add it
                res = str1[i - 1] + res;  // concatenate char in the front
                --i;
            } else if (j > 0 && dp[i][j] == dp[i][j - 1]) {
                res = str2[j - 1] + res;
                --j;
            } else {  // if i or j is 0, it will not reach this else, dp[0][2] == dp[0][3] always true
                res = str1[i - 1] + res;
                --i;
                --j;
            }
            
        }
        
        return res;
    }
    
};