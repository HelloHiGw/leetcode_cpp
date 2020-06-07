/*
dfs + memo

Time: O(n * log10(k)), where n <= 10^5 is the length of string s, k <= 10^9 => log10(k) <= 9
Explain: There are total n states, each state needs maximum log10(k) iteration loops to 
calculate the result.

Space: O(n)
*/
class Solution {
public:
    int numberOfArrays(string s, int k) {
        vector<int> memo(s.size(), -1);
        return dfs(0, k, s, memo);
    }
    
private:
    const int MOD = 1e9 + 7;
    
    int dfs(int start, int k, string& s, vector<int>& memo) {
        if (start == s.size()) return 1;
        if (s[start] == '0') return 0;
        if (memo[start] != -1) return memo[start];  // there is no memo in backtracking, because we want a complete path when reaching the end, here is simple search

        int res = 0;
        long num = 0;  // num may be bigger than INT_MAX
        for (int i = start; i < s.size(); ++i) {
            num = num * 10 + s[i] - '0';
            if (num > k) break;
            res = (res + dfs(i + 1, k, s, memo)) % MOD;
        }

        return memo[start] = res;
    }
};



/*
if the above is top-down, then 0 is top, s.size() is bottom
if we want bottom-up dp, the base case is at s.size()
this is different from norm

bottom up is also O(n * log10(k)) time
*/
class Solution {
public:
    int numberOfArrays(string s, int k) {
        const int MOD = 1e9 + 7;
        vector<int> dp(s.size() + 1, 0);
        dp[s.size()] = 1;

        for (int i = s.size() - 1; i >= 0; --i) {
            if (s[i] == '0') continue;
            
            long num = 0;
            for (int j = i; j < s.size(); ++j) {
                num = num * 10 + s[j] - '0';
                if (num > k) break;
                dp[i] = (dp[i] + dp[j + 1]) % MOD;
            }
        }

        return dp[0];
    }
};
