/*
time O(n * n * 3)
space O(n * n)
*/
class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& A) {
        const int INF = 0x3fffffff;
        int m = A.size(), n = A[0].size();
        // dp[i][j], the minimum sum falling to arr[i][j]
        // initialize INF for minimum
        vector<vector<int>> dp(m, vector<int>(n, INF));
        dp[0] = A[0];
        
        for (int i = 1; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                for (int k = j - 1; k <= j + 1; ++k) {
                    if (k < 0 || k >= n) continue;
                    dp[i][j] = min(dp[i][j], dp[i - 1][k] + A[i][j]);
                }
            }
        }
        
        int res = INT_MAX;
        for (int j = 0; j < n; ++j) {
            res = min(res, dp[m - 1][j]);
        }
        return res;
    }
};


/*
time O(n * n * 3)
space O(n)
*/
class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& A) {
        int m = A.size(), n = A[0].size();
        vector<int> prev = A[0], curr(n);
        
        for (int i = 1; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                curr[j] = INT_MAX;
                for (int k = j - 1; k <= j + 1; ++k) {
                    if (k < 0 || k >= n) continue;
                    curr[j] = min(curr[j], prev[k] + A[i][j]);
                }
            }
            swap(prev, curr);
        }
        
        int res = INT_MAX;
        for (int j = 0; j < n; ++j) {
            res = min(res, prev[j]);
        }
        return res;
    }
};