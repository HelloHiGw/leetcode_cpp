/*
We can divide this problem to two sub problems to break the circle (break the circle so
we can get the base case of dp)

Let's take following example:
Subproblem 1: rob house 1 ~ 8
Subproblem 2: rob house 2 ~ 9
And find the bigger one of these two sub problems.
*/

class Solution {
public:
    int rob(vector<int>& nums) {
        if (nums.empty()) return 0;
        if (nums.size() == 1) return nums[0];
        if (nums.size() == 2) return max(nums[0], nums[1]);  // at least 3 numbers
        return max(robRange(nums, 1, nums.size() - 1), robRange(nums, 2, nums.size()));  // ith
    }

private:
    int robRange(vector<int> &nums, int start, int end) {
        vector<int> dp(end + 1);
        dp[start] = nums[start - 1];
        for (int i = start + 1; i <= end; ++i) {
            dp[i] = max(dp[i - 1], dp[i - 2] + nums[i - 1]);  // ith
        }
        return dp[end];
    }
};


class Solution {
public:
    int rob(vector<int>& nums) {
        if (nums.empty()) return 0;
        if (nums.size() == 1) return nums[0];
        if (nums.size() == 2) return max(nums[0], nums[1]);  // at least 3 numbers
        return max(robRange(nums, 1, nums.size() - 1), robRange(nums, 2, nums.size()));
    }

private:
    int robRange(vector<int> &nums, int start, int end) {
        int prev2 = 0, prev = nums[start - 1];
        for (int i = start + 1; i <= end; ++i) {
            int curr = max(prev, prev2 + nums[i - 1]);
            prev2 = prev;
            prev = curr;
        }
        return prev;
    }
};