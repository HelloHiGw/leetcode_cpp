/*
really hard to understand

We first keep in mind that s is the longer string [0, i-1], t is the shorter substring [0, 
j-1]. We can assume t is fixed, and s is increasing in character one by one (this is the key point).

For example:
t : ab--> ab --> ab --> ab
s: a --> ac --> acb --> acbb

The first case is easy to catch. When the new character in s, s[i-1], is not equal with the head char 
in t, t[j-1], we can no longer increment the number of distinct subsequences, it is the same as the 
situation before incrementing the s, so dp[i][j] = dp[i-1][j].

However, when the new incrementing character in s, s[i-1] is equal with t[j-1], which contains two case:

We don't match those two characters, which means that it still has original number of distinct subsequences, 
so dp[i][j] = dp[i-1][j].

We match those two characters, in this way. dp[i][j] = dp[i-1][j-1];
Thus, including both two case, dp[i][j] = dp[i-1][j] + dp[i-1][j-1]

time O(m * n)
space O(m * n)

simplely put
a b b
a b

dp[3][2] = dp[2][2](do not match) + dp[2][1](match) = 1 + 1 = 2
*/
class Solution {
public:
    int numDistinct(string s, string t) {
        int m = s.size(), n = t.size();
        vector<vector<long>> dp(m + 1, vector<long>(n + 1));
        for (int i = 0; i <= m; ++i) dp[i][0] = 1;
        
        for (int j = 1; j <= n; ++j) {
            for (int i = 1; i <= m; ++i) {
                if (s[i - 1] == t[j - 1]) {
                    dp[i][j] = dp[i - 1][j] + dp[i - 1][j - 1];
                } else {
                    dp[i][j] = dp[i - 1][j];
                }
            }
        }
        
        return dp[m][n];
    }
};