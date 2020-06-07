class Solution {
public:
    int countSubstrings(string s) {
        int n = s.size();
        vector<vector<bool>> dp(n, vector<bool>(n, false));
        int res = 0;
        
        for (int i = n - 1; i >= 0; --i) {
            for (int j = i; j < n; ++j) {
                if (j == i || j == i + 1) {
                    dp[i][j] = s[i] == s[j];
                } else {
                    dp[i][j] = (s[i] == s[j]) && dp[i + 1][j - 1];
                }
                
                if (dp[i][j]) ++res;
            }
        }
        
        return res;
    }
};


class Solution {
public:
    int countSubstrings(string s) {
        int n = s.size();
        int res = 0;
        
        for (int i = 0; i < n; ++i) {
            res += extend(i, i, s);
            res += extend(i, i + 1, s);
        }
        
        return res;
    }
    
private:
    int extend(int i, int j, string& s) {
        int count = 0;
        while (i >= 0 && j < s.size() && s[i] == s[j]) {
            --i;
            ++j;
            ++count;  // if can extend, it is a new palindrome
        }
        return count;
    }
};

