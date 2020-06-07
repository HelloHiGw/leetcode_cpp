class Solution {
public:
    int minimumDeleteSum(string s1, string s2) {
        int n1 = s1.size(), n2 = s2.size();
        // dp[0][0] = 0
        vector<vector<int>> dp(n1 + 1, vector<int>(n2 + 1, 0));
        
        for (int i = 1; i <= n1; ++i) { // s1.substr(0, i) and ""
            dp[i][0] = dp[i - 1][0] + s1[i - 1];
        }
        for (int j = 1; j <= n2; ++j) {  // "" and s2.substr(0, j)
            dp[0][j] = dp[0][j - 1] + s2[j - 1];
        }
        
        for (int i = 1; i <= n1; ++i) {
            for (int j = 1; j <= n2; ++j) {
                if (s1[i - 1] == s2[j - 1]) {
                    dp[i][j] = dp[i - 1][j - 1];
                } else {
                    dp[i][j] = min(dp[i - 1][j] + s1[i - 1], dp[i][j - 1] + s2[j - 1]);
                }
            }
        }
        
        return dp[n1][n2];
    }
};


class Solution {
public:
    int minimumDeleteSum(string s1, string s2) {
        int n1 = s1.size(), n2 = s2.size();
        if (n2 > n1) return minimumDeleteSum(s2, s1);
        
        vector<int> prev(n2 + 1), curr(n2 + 1);
        for (int j = 1; j <= n2; ++j) {
            prev[j] = prev[j - 1] + s2[j - 1];
        }
        
        for (int i = 1; i <= n1; ++i) {
            // here is very very tricky!!! use curr[0] to store dp[i][0]
            // really hard to understand..
            curr[0] = prev[0] + s1[i - 1];
            
            for (int j = 1; j <= n2; ++j) {
                
                if (s1[i - 1] == s2[j - 1]) {
                    curr[j] = prev[j - 1];
                } else {
                    curr[j] = min(prev[j] + s1[i - 1], curr[j - 1] + s2[j - 1]);
                }
    
            }
            swap(prev, curr);
        }
        
        return prev[n2];
    }
};
