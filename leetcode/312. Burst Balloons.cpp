/*
dp[i][j] the maximum coins we get after we burst all the balloons between i and j in the 
original array. (between i and j, [i, j])

for (int k = left; k <= right; ++k)
dp[left][right] = max(dp[left][right], nums[left-1] * nums[k] * nums[right+1] + dp[left][k-1] + dp[k+1][right])

This transition function basically says in order to get the maximum value we can get for bursting all the 
balloons between [ i , j] , we just loop through each balloon between these two indexes and make them to 
be the [last](!!!) balloon to be burst


For example when calculating dp[1,4] and picking index 2 as the last balloon to burst,

1 [ 3 , 1 , 5 , 8] 1, that means 5 is the last balloon to burst between [1,4] , to get the maximum value when picking 5 as the last balloon to burst :

max = maximum value of bursting all the balloon on the left side of 5 + maximum value of bursting all the 
balloon on the right side of 5 + bursting balloon 5 when left side and right side are gone.

That is dp[1, 2] + nums[1 - 1] * nums[3] * nums[4 + 1] + + dp[4,4];

That is dp[left, k - 1] + nums[left - 1] * nums[k] * nums[right + 1] + dp[k+1, right] ;

to get the maximum dp[left, right] we just loop through all the possible value of k to get the maximum.
from small section length to bigger section length

k在区间 [i, j] 中，假如第k个气球最后被打爆，则之前区间 [i, j] 被分成了两部分，[i, k-1] 和 [k+1, j]，只要我们之前更新过了这两个子区间的dp值，可以直接用 dp[i][k-1] 和 dp[k+1][j]
*/

class Solution {
public:
    int maxCoins(vector<int>& nums) {
        int n = nums.size();
        nums.insert(nums.begin(), 1);
        nums.push_back(1);
        vector<vector<int>> dp(n + 2, vector<int>(n + 2, 0));
        
        for (int l = 1; l <= n; ++l) {
            for (int i = 1, j = l; j <= n; ++i, ++j) {  // j = l, not j = l - 1, it is 1-based now
                for (int k = i; k <= j; ++k) {
                    int val = nums[i - 1] * nums[k] * nums[j + 1];
                    dp[i][j] = max(dp[i][j], dp[i][k - 1] + val + dp[k + 1][j]);
                }
            }
        }
        
        return dp[1][n];
    }
};