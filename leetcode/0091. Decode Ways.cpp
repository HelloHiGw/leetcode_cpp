class Solution {
public:
    int numDecodings(string s) {
        if (s.empty()) return 0;
        int n = s.size();
        vector<int> dp(n + 1, 0);
        dp[0] = 1;
        dp[1] = s[0] != '0';
        
        for (int i = 2; i <= n; ++i) {
            int currDigit = s[i - 1] - '0';
            int prevDigit = stoi(s.substr(i - 2, 2));
            if (currDigit >= 1 && currDigit <= 9) dp[i] += dp[i - 1];
            if (prevDigit >= 10 && prevDigit <= 26) dp[i] += dp[i - 2];
        }
        return dp[n];
    }
};


class Solution {
public:
    int numDecodings(string s) {
        if (s.empty()) return 0;
        int n = s.size();
        int prev2 = 1, prev = s[0] != '0';
        
        for (int i = 2; i <= n; ++i) {
            int currDigit = s[i - 1] - '0';
            int prevDigit = stoi(s.substr(i - 2, 2));
            int curr = 0;
            if (currDigit >= 1 && currDigit <= 9) curr += prev;
            if (prevDigit >= 10 && prevDigit <= 26) curr += prev2;
            prev2 = prev;
            prev = curr;
        }
        return prev;
    }
};

