/*
greedy

*/

class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        if (nums.empty()) return 0;
        int preDiff = 0, res = 1;
        for (int i = 1; i < nums.size(); ++i) {
            int diff = nums[i] - nums[i - 1];
            if (diff > 0 && preDiff <= 0 || diff < 0 && preDiff >= 0) {
                ++res;
                preDiff = diff;  // preDiff will not be 0, unless for the leading same elements
            }
        }
        return res;
    }
};

/*
the idea of LIS
O(n ^ 2)
*/

class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        int n = nums.size();
        // dp[i][0], ending at nums[i], the max wiggle sequence length (last difference is positive)
        // dp[i][1], ending at nums[i], the max wiggle sequence length (last difference is negative)
        // initialization is 1(self-length)
        vector<vector<int>> dp(n, vector<int>(2, 1));
        
        int res = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < i; ++j) {
                if (nums[j] < nums[i] && dp[j][1] + 1 > dp[i][0]) {
                    dp[i][0] = dp[j][1] + 1;
                } else if (nums[j] > nums[i] && dp[j][0] + 1 > dp[i][1]) {
                    dp[i][1] = dp[j][0] + 1;
                }
            }
            
            res = max(dp[i][0], dp[i][1]);
        }
        
        return res;
    }
};


/*
the above is using another for loop (for j) to get the subsequence
this is because dp[i] is wiggle sequence ending at nums[i]

now we change the definition of dp
dp[i] is the max wiggle sequence for nums[0] to nums[i]

when confronting a mismatch, dp[i] should inherit from dp[i - 1] to maintain
the property of subsequence
*/

class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        if (nums.empty()) return 0;
        int n = nums.size();
        // dp[i][0], nums[0:i(inclusive)], the max wiggle sequence length (last difference is positive)
        // dp[i][1], nums[0:i(inclusive)], the max wiggle sequence length (last difference is negative)
        vector<vector<int>> dp(n, vector<int>(2, 0));
        dp[0][0] = dp[0][1] = 1;
        
        int res = 0;
        for (int i = 1; i < n; ++i) {
            if (nums[i] > nums[i - 1]) {
                dp[i][0] = dp[i - 1][1] + 1;
                dp[i][1] = dp[i - 1][1];
            } else if (nums[i] < nums[i - 1]) {
                dp[i][1] = dp[i - 1][0] + 1;
                dp[i][0] = dp[i - 1][0];
            } else {
                dp[i][0] = dp[i - 1][0];
                dp[i][1] = dp[i - 1][1];
            }
        }
        
        return max(dp[n - 1][0], dp[n - 1][1]);
    }
};

