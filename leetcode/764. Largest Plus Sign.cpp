/*
dp[i][j] = min({dp[i - 1][j], dp[i][j - 1], dp[i + 1][j], dp[i][j + 1]}) + 1 is false
proof case:
0 0 1 0 0
0 0 1 0 0
1 1 1 1 1
0 0 1 0 0
0 0 1 0 0 

brute force is O(N^3), O(N) for extending
*/
class Solution {
public:
    int orderOfLargestPlusSign(int N, vector<vector<int>>& mines) {
        vector<vector<int>> grid(N, vector<int>(N, 1));
        for (auto& v : mines) {
            grid[v[0]][v[1]] = 0;
        }
        
        vector<vector<int>> dp(N, vector<int>(N, INT_MAX / 2));
        
        for (int i = 0; i < N; ++i) {
            // left is the continuous 1s in the left side(including self)
            for (int j = 0, left = 0; j < N; ++j) {
                dp[i][j] = min(dp[i][j], left = (grid[i][j] == 0 ? 0 : ++left));
            }
            for (int j = N - 1, right = 0; j >= 0; --j) {
                dp[i][j] = min(dp[i][j], right = (grid[i][j] == 0 ? 0 : ++right));
            }
            
            // tackle with index i column, it is a mirror of row
            // you can also start a new for for 
            for (int k = 0, up = 0; k < N; ++k) {
                dp[k][i] = min(dp[k][i], up = (grid[k][i] == 0 ? 0 : ++up));
            }
            for (int k = N - 1, down = 0; k >= 0; --k) {
                dp[k][i] = min(dp[k][i], down = (grid[k][i] == 0 ? 0 : ++down));
            }
        }
        
        int res = 0;
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < N; ++j) {
                res = max(res, dp[i][j]);
            }
        }
        
        return res;
    }
};