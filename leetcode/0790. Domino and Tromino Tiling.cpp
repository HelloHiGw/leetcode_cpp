/*
dp[n]=dp[n-1]+dp[n-2]+ 2*(dp[n-3]+...+d[0])
=dp[n-1]+dp[n-2]+dp[n-3]+dp[n-3]+2*(dp[n-4]+...+d[0])
=dp[n-1]+dp[n-3]+(dp[n-2]+dp[n-3]+2*(dp[n-4]+...+d[0]))
=dp[n-1]+dp[n-3]+dp[n-1]
=2*dp[n-1]+dp[n-3]

Here is my understanding of why dp[n] = dp[n-1] + dp[n-2] + dp[n-3] * 2 + ... dp[0] * 2:
For all f(n-1), it can be transformed to f(n) by appending a domino |, hence f(n - 1) * 1.
For all f(n - 2), though f(2) contains 2 cases: = and ||, however the case || has been covered by f(n - 1) plus |,
so literally there is only one distinct way to transform f(n-2) to f(n), hence f(n - 2) * 1.

For all f(n - i) where i > 2, the ways complementing them to f(n) by dominoes 
(either horizontal or vertical domino) have been covered by f(n - 1) and f(n - 2),
hence the remaining distinct ways are either appending triminoes or combination of triminoes and 
dominoes. And there are always only 2 ways to do this.

dp[i - 3]
x x y   x y y
x y y   x x y

dp[i - 4]
x x y y   x z z y
x z z y   x x y y 

dp[i - 5]
x x z z y   x z z y y
x z z y y   x x z z y

dp[i - 6], 
x x z z y y   x z z z z y
x z z z z y   x x z z y y

you cannot incise at any position between j and j + 1, 
because there is a horizontal tile lying at it
x x     z z     y y 
x   z z     z z   y
*/
class Solution {
public:
    int numTilings(int N) {
        if (N <= 2) return N;
        if (N == 3) return 5;
        
        const int MOD = 1e9 + 7;
        vector<long> dp(N + 1);
        dp[1] = 1;
        dp[2] = 2;
        dp[3] = 5;
        
        for (int i = 4; i <= N; ++i) {
            dp[i] = (2 * dp[i - 1] % MOD + dp[i - 3]) % MOD;
        }
        
        return dp[N];
    }
};

class Solution {
public:
    int numTilings(int N) {
        if (N <= 2) return N;
        if (N == 3) return 5;
        
        const int MOD = 1e9 + 7;
        long dp3 = 1, dp2 = 2, dp1 = 5;
        
        for (int i = 4; i <= N; ++i) {
            long curr = (2 * dp1  % MOD + dp3) % MOD;
            dp3 = dp2;
            dp2 = dp1;
            dp1 = curr;
        }
        
        return dp1;
    }
};