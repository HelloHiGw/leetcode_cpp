/*
dp[i][j] is the maximum dot product of equal length subsequences of nums1[0,i) and nums2[0, j).

For dp[0][j] and dp[i][0], they mean that either s or t is empty array. Since the question is 
asking for non-empty subsequences, they are not valid cases, so we should regard them as -INF.
(legal answer should at least contain 1 number for each array)

consider case [3], [-2]
dp[1][1] = max({3 * (-2), dp[0][1], dp[1][0], dp[0][0] + 3 * (-2)}) = max({-6, 0, 0, -6}) = 0 
if you set dp[i][0] = dp[0][j] = 0, which is incorrect

For dp[i][j], we have three choices:

We include s[i - 1] and t[j - 1] in the subsequences. 
we get dp[i - 1][j - 1] + s[i - 1] * t[j - 1]   or simply   s[i - 1] * t[j - 1]
that is max(0, dp[i - 1][j - 1]) + s[i - 1] * t[j - 1].
take max() because dp[i-1][j-1] might be smaller than 0. e.g. nums1 = [-1, -6] nums2=[1, -2]

We ignore s[i - 1] and reuse the result of dp[i - 1][j].
We ignore t[j - 1] and reuse the result of dp[i][j - 1].

dp[i + 1][j + 1] = max(
s[i - 1] * t[j - 1],              // If we include s[i - 1] and t[j - 1] in the subsequences
dp[i - 1][j - 1] + s[i - 1] * t[j - 1] 

dp[i - 1][j],                     // If we don't include s[i - 1] in the subsequence
dp[i][j - 1]                      // If we don't include t[j - 1] in the subsequence
)
dp[0][j] = dp[i][0] = -INF 


For the transfer function, what if we want to ignore both the last numbers?

Actually it's not necessary to consider, because in that case dp(X, Y) would be dp(X-1, Y-1).
If dp(X-1, Y-1) is indeed the actual answer, it will propagate via dp(X-1, Y) or dp(X, Y-1).

Why?
dp(X-1, Y) = max(dp(X-1, Y-1) ,
dp(X-2, Y),
nums1[X-1]*nums2[Y],
dp(X-2, Y-1) + nums1[X-1]*nums2[Y])
Similarly for F(X, Y-1) = ....
*/
class Solution {
public:
    int maxDotProduct(vector<int>& nums1, vector<int>& nums2) {
        const int INF = 0x3fffffff;
        int m = nums1.size(), n = nums2.size();
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, -INF));
        
        for (int i = 1; i <= m; ++i) {
            for (int j = 1; j <= n; ++j) {
                dp[i][j] = max({dp[i - 1][j], dp[i][j - 1], nums1[i - 1] * nums2[j - 1] + max(dp[i - 1][j - 1], 0)});
            }
        }
        
        return dp[m][n];
    }
};


/*
我想问一下 什么是“padding?”可不可以直接初始化下dp【0】【0】？

padding 就是 dp【i+1】【j+1】 对应 nums1【i】/nums2【j】，没有padding就是 dp【i】【j】 对应 nums1【i】/nums2【j】.

使用padding的时候，只初始化dp【0】【0】是不够的，需要初始化所有能访问到的越界（非法）子问题 dp【0】【*】, dp【*】【0】。


*/
class Solution {
public:
    int maxDotProduct(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size(), n = nums2.size();
        vector<vector<int>> dp(m, vector<int>(n));
        
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                dp[i][j] = nums1[i] * nums2[j];
                if (i && j) dp[i][j] += max(dp[i - 1][j - 1], 0);
                if (i) dp[i][j] = max(dp[i][j], dp[i - 1][j]);
                if (j) dp[i][j] = max(dp[i][j], dp[i][j - 1]);
            }
        }
        
        return dp[m - 1][n - 1];
    }
};