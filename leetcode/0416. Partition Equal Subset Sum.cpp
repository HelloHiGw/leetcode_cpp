/class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int total = 0;
        for (int num : nums) total += num;
        if (total % 2 != 0) return false;
        total /= 2;
        
        int n = nums.size();
        // dp[i][j] denotes whether the first i element can sum up to j
        vector<vector<bool>> dp(n + 1, vector<bool>(total + 1,  false));
        for (int i = 0; i <= n; ++i) dp[i][0] = true;  // this is obvious
        
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= total; ++j) {
                if (j < nums[i - 1]) {  
                    dp[i][j] = dp[i - 1][j];
                } else {
                    dp[i][j] = dp[i - 1][j] || dp[i - 1][j - nums[i -  1]];
                }
            }
        }
        
        return dp[n][total];
    }
};


class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int total = 0;
        for (int num : nums) total += num;
        if (total % 2 != 0) return false;
        total /= 2;
        
        int n = nums.size();
        vector<bool> dp(total + 1, false);
        dp[0] = true;
        
        for (int i = 1; i <= n; ++i) {
            for (int j = total; j >= 1; --j) {
                if (j < nums[i - 1]) {  
                    dp[j] = dp[j];
                } else {
                    dp[j] = dp[j] || dp[j - nums[i - 1]];
                }
            }
        }
        
        return dp[total];
    }
};


class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int total = 0;
        for (int num : nums) total += num;
        if (total % 2 != 0) return false;
        total /= 2;
        
        int n = nums.size();
        vector<bool> dp(total + 1, false);
        dp[0] = true;
        
        for (int i = 1; i <= n; ++i) {
            for (int j = total; j >= nums[i - 1]; --j) {
                dp[j] = dp[j] || dp[j - nums[i - 1]];
            }
        }
        
        return dp[total];
    }
};

/*
when right to left ?
dp[j] = dp[i - 1][j] for current j position no matter left to right or right to left
form right to left dp[j - num] means dp[i - 1][j - num]
from left to right dp[j - num] means dp[i][j - num]

if we go from left to right, the dp[i - num] has been updated with current iteration
the status from last iteration is lost.
*/