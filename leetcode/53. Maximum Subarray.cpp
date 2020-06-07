// class Solution {
// public:
//     int maxSubArray(vector<int>& nums) {
//         if (nums.empty()) return 0;
//         vector<int> dp(nums.size());
//         dp[0] = nums[0];
//         int res = dp[0];
//         for (int i = 1; i < nums.size(); ++i) {
//             dp[i] = max(nums[i], dp[i - 1] + nums[i]);
//             res = max(res, dp[i]);
//         }
//         return res;
//     }
// };


class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        if (nums.empty()) return 0;
        int maxEndingHere = nums[0];
        int res = nums[0];
        for (int i = 1; i < nums.size(); ++i) {
            maxEndingHere = max(nums[i], maxEndingHere + nums[i]);
            res = max(res, maxEndingHere);
        }
        return res;
    }
};