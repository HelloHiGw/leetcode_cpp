/*
dp[i] is the probability that we get points i 

When the game ends, the point is between K and K-1+W

the answer we want is has N or less points
dp[K] + dp[K + 1] + ... + dp[N]

here comes a problem, how we calculate dp[i] ?
i = (i - 1  + 1) or (i - 2 + 2) or (i - 3 + 3) ... or (i - W + W)
because every round, we can only get new point from [1 to W]
we cannot jump from i - W - 1 to i(need W + 1)

so
dp[i] = dp[i - 1] / W + dp[i - 2] / W + dp[i - 3] / W + ... + dp[i - W] / W
= probability sum (dp[i - W] + ... + dp[i - 2] + dp[i - 1]) / W
(we get any point in [1, W] with equal probability 1 / W)

thus we can use sliding window to update the probability sum

*/

class Solution {
public:
    double new21Game(int N, int K, int W) {
        if (N > K - 1 + W || K == 0) return 1;
        vector<double> dp(N + 1);
        dp[0] = 1;
        double probSum = 1;
        double res = 0;
        
        for (int i = 1; i <= N; ++i) {
            dp[i] = probSum / W;
            
            // e.g. dp[K + 2] cannot generate from dp[K + 1] amd dp[K]
            // because when i >= K, it stops drawing
            if (i < K) {
                probSum += dp[i];
            } else if (i >= K) {
                res += dp[i];
            }
            
            // maintain window size of W
            if (i >= W) probSum -= dp[i - W];
        }
        
        return res;
    }
};