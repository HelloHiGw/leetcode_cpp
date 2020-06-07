/*
time O(m * target * n * n)
space O(m * target * n)
*/
class Solution {
public:
    int minCost(vector<int>& houses, vector<vector<int>>& cost, int m, int n, int target) {
        const int INF = 0x3fffffff;
        int s = 1;
        // dp[i][j][c], the min cost to paint the first i houses in j neighborhoods with the ith color c
        vector<vector<vector<int>>> dp(m + 1, vector<vector<int>>(target + 1, vector<int>(n + 1, INF)));
        for (int c = 0; c <= n; ++c) dp[0][0][c] = 0;
        
        for (int i = 1; i <= m; ++i) {
            for (int j = 1; j <= target; ++j) {
                int ci = houses[i - 1];  // color i
                int cp = i > 1 ? houses[i - 2] : 0;  // color previous
                auto [si, ei] = ci ? tie(ci, ci) : tie(s, n);  // start and end of current color
                auto [sp, ep] = cp ? tie(cp, cp) : tie(s, n);  // start and end of previous color
                for (int c = si; c <= ei; ++c) {
                    int costi = houses[i - 1] == c ? 0 : cost[i - 1][c - 1];
                    for (int p = sp; p <= ep; ++p) {
                        // have to been min here
                        // consider [1, 1, 2] [1, 2, 2], i = 3, j = 2, c = 2, we need the minimum one
                        dp[i][j][c] = min(dp[i][j][c], dp[i - 1][j - (c != p)][p] + costi);
                    }
                }
            }
        }
        
        int res = *min_element(dp[m][target].begin(), dp[m][target].end());
        return res >= INF ? -1 : res;
    }
};