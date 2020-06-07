// // naive TLE
// class Solution {
// public:
//     int findTargetSumWays(vector<int>& nums, int S) {
//         int res = 0;
//         dfs(0, 0, S, res, nums);
//         return res;
//     }

// private:
//     void dfs(int index, int sum, int target, int &res, vector<int>& nums) {
//         if (index == nums.size()) {
//             if (sum == target) ++res;
//             return;
//         }
//         dfs(index + 1, sum + nums[index], target, res, nums);
//         dfs(index + 1, sum - nums[index], target, res, nums);
//     }
// };

// suffixSum 1624 ms, faster than 5.07%
// class Solution {
// public:
//     int findTargetSumWays(vector<int>& nums, int S) {
//         int res = 0;
//         vector<int> suffixSum(nums.size());
//         suffixSum.back() = nums.back();
//         for (int i = nums.size() - 2; i >= 0; --i) {
//             suffixSum[i] += suffixSum[i + 1] + nums[i];
//         }
//         dfs(0, 0, S, res, nums, suffixSum);
//         return res;
//     }

// private:
//     void dfs(int index, int sum, int target, int &res, vector<int>& nums, vector<int>& suffixSum) {
//         if (index == nums.size()) {
//             if (sum == target) ++res;
//             return;
//         }
//         if (suffixSum[index] + sum < target) return;
//         dfs(index + 1, sum + nums[index], target, res, nums, suffixSum);
//         dfs(index + 1, sum - nums[index], target, res, nums, suffixSum);
//     }
// };

/*
time O(n * target)  <= O(n * (1000 + S) / 2) = O(n * S), much better than above O(2 ^ n)
space O(n * target)
*/
class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int S) {
        int total = 0;
        for (int num : nums) total += num;
        
        // case [1,2,7,9,981] 1000000000 MLE, so we need return false here
        if (total < S) return 0;
        
        if ((total + S) % 2 != 0) return 0;
        int target = (total + S) / 2;
        
        int n = nums.size();
        // dp[i][j] denotes the ways for the first i numbers to form sum j
        vector<vector<int>> dp(n + 1, vector<int>(target + 1, 0));
        
        // attention, you can only initialize dp[0][0] = 1, no dp[i][0] = 1 (0 <= i <= n)
        // case [0, 0, 0, 1] 1 dp[1][0] shoulde be 2, not 1
        // dp[1][0] = dp[0][0] + dp[0][0 - 0] = 1 + 1 = 2
        dp[0][0] = 1;
        
        for (int i = 1; i <= n; ++i) {
            for (int j = 0; j <= target; ++j) {
                if (j < nums[i - 1]) {
                    dp[i][j] = dp[i - 1][j];
                } else {
                    dp[i][j] = dp[i - 1][j] + dp[i - 1][j - nums[i - 1]];
                }
            }
        }
        
        return dp[n][target];
    }
};


class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int S) {
        int total = 0;
        for (int num : nums) total += num;
        
        if (total < S) return 0;
        if ((total + S) % 2 != 0) return 0;
        int target = (total + S) / 2;
        
        int n = nums.size();
        vector<int> dp(total + 1, 0);
        dp[0] = 1;
        
        for (int i = 1; i <= n; ++i) {
            for (int j = target; j >= nums[i - 1]; --j) {
                dp[j] += dp[j - nums[i - 1]];
            }
        }
        
        return dp[target];
    }
};

