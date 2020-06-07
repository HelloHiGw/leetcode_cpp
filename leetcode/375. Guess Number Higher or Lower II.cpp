/*

dp[i][j] the minimum cost of guaranteeing guess a number successfully in [i, j]

dp[i][j] is the minimal cost to guess from range(i...j).
When you choose an x where i <= x <= j, you may find the target number from left i...x-1, or you 
may find the target number from the x+1...j, because you don't know which way should go, so to 
guarantee you have enough money to find the target, you need to prepare the more, which is 
max(dp[i][x-1], dp[x+1][j]).

the minimum valid length should 2, because we all know we don't have to cost a single penny to 
guarantee a win when i==j; 

we set n + 2 of dp to make dp[n + 1][n] will not out of boundary
to compute dp[1][n], if we first choose n, it becomes
max(dp[1][n - 1], dp[n + 1][n]) + n;


boundary case
dp[i][j] = 0 (i >= j)
*/
class Solution {
public:
    int getMoneyAmount(int n) {
        vector<vector<int>> dp(n + 2, vector<int>(n + 2, 0));
        
        for (int l = 2; l <= n; ++l) {
            for (int i = 1, j = l; j <= n; ++i, ++j) {
                dp[i][j] = INT_MAX;
                for (int k = i; k <= j; ++k) {
                    dp[i][j] = min(dp[i][j], max(dp[i][k - 1], dp[k + 1][j]) + k);
                }
            }
        }
        
        return dp[1][n];
    }
};