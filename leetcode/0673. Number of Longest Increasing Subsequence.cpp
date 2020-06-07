class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n, 0);  // the length of LIS ending at nums[i]
        vector<int> count(n, 0);  // the count of different LIS ending at nums[i]
        
        int maxLen = 0;
        int res = 0;
        
        for (int i = 0; i < n; ++i) {
            dp[i] = 1; // boundary
            count[i] = 1;
            
            for (int j = 0; j < i; ++j) {
                if (nums[j] >= nums[i]) continue;
                if (dp[j] + 1 > dp[i]) {
                    dp[i] = dp[j] + 1;
                    count[i] = count[j];
                } else if (dp[j] + 1 == dp[i]) {
                    count[i] += count[j];  // not ++count[i]
                }
            }
            
            if (dp[i] > maxLen) {
                maxLen = dp[i];
                res = count[i];
            } else if (dp[i] == maxLen) {
                res += count[i];
            }
            
        }
        
        return res;
    }
};