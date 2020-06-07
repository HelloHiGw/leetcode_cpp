class Solution {
public:
    int splitArray(vector<int>& nums, int m) {
        int n = nums.size();
        // there is [1, INT_MAX] 1 text case
        vector<vector<long>> dp(m + 1, vector<long>(n + 1, LONG_MAX / 2));
        dp[0][0] = 0;
        
        for (int i = 1; i <= m; ++i) {
            for (int j = 1; j <= n; ++j) {
                long sum = 0;
                for (int k = j - 1; k >= i - 1; --k) {
                    sum += nums[k];  // k + 1(next) - 1(0-based nums)
                    dp[i][j] = min(dp[i][j], max(dp[i - 1][k], sum));
                }
            }
        }
        
        return dp[m][n];
    }
};s