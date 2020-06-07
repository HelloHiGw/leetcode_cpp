class Solution {
public:
    int maximumSum(vector<int>& nums) {
        if (nums.empty()) return 0;
        int n = nums.size();
        // dp[i][0] Maximum Subarray Sum ending at nums[i] without deletion
        // dp[i][0] Maximum Subarray Sum ending at nums[i] with one deletion
        vector<vector<int>> dp(n, vector<int>(2, INT_MIN));
        dp[0][0] = nums[0];
        dp[0][1] = 0;
        
        // not res = max(dp[0][0], dp[0][1]), cause dp[0][1] there is no number
        // constraint : non-empty subarray
        int res = dp[0][0];
        for (int i = 1; i < n; ++i) {
            dp[i][0] = max(nums[i], dp[i - 1][0] + nums[i]);
            dp[i][1] = max(dp[i - 1][0] + 0, dp[i - 1][1] + nums[i]);  // at most one deletion
            res = max(res, max(dp[i][0], dp[i][1]));
        }
        
        return res;
    }
};


class Solution {
public:
    int maximumSum(vector<int>& nums) {
        if (nums.empty()) return 0;
        int n = nums.size();
        
        int noDelete = nums[0];
        int oneDelete = 0;
        int res = noDelete;
        
        for (int i = 1; i < n; ++i) {
            int noDeleteI = max(nums[i], noDelete + nums[i]);
            int oneDeleteI = max(noDelete, oneDelete + nums[i]);
            noDelete = noDeleteI;
            oneDelete = oneDeleteI;
            res = max(res, max(noDelete, oneDelete));
        }
        
        return res;
    }
};