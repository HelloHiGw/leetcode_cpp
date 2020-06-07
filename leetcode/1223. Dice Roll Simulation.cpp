/*
case 1
i == rollMax[j] + 1, if rollMax(4) = 3
when current is number 4
* * * 4
dp[4][3] = dp[3][6]

but we have to remove the case (current cannnot be 4)
4 4 4 4
so dp[4][3]--;


case 2
i > rollMax[j] + 1, if rollMax(4) = 3
when current is number 4
a b c * * * 4
dp[7][3] = dp[6][6]

but we do not want to see the case a b c 4 4 4 4
so we need to find how many count with tail as 4 4 4 
that is 1 4 4 4,  2 4 4 4,  3 4 4 4,  5 4 4 4,  6 4 4 4
i.e.  a b 1, a b 2, a b 3, a b 5, a b 6 
(except a b 4, because a b 4  4 4 4 not exists, it has been removed by case 1)

removeCount = dp[3][6] - dp[3][3]


(+MOD) here is to avoid negative values. Example: (6 - 5) % 3 = 1, but (6%3 - 5%3) = -2 
we need to add 3 to make it as positive value.
*/

class Solution {
public:
    int dieSimulator(int n, vector<int>& rollMax) {
        const int MOD = 1e9 + 7;
        // dp[i][j], after rolling i times, the count with last number of j(0-based)
        vector<vector<int>> dp(n + 1, vector<int>(7));
        for (int i = 0; i < 6; ++i) dp[1][i] = 1;
        // dp[i][6], after rolling i times, the total count of numbers
        dp[1][6] = 6;
        
        for (int i = 2; i <= n; ++i) {
            int total = 0;
            for (int j = 0; j < 6; ++j) {
                // if no constraint, this roll ending with j is dp[i - 1][6]
                dp[i][j] = dp[i - 1][6];
                // has nothing to concern when i <= rollMax[j]
                
                if (i == rollMax[j] + 1) {
                    --dp[i][j];
                } else if (i > rollMax[j] + 1) {
                    int removeIndex = i - rollMax[j] - 1;
                    int removeCount = dp[removeIndex][6] - dp[removeIndex][j];
                    dp[i][j] = ((dp[i][j] - removeCount) % MOD + MOD) % MOD;
                }
                total = (total + dp[i][j]) % MOD;
            }
            dp[i][6] = total;
        }
        
        return dp[n][6];
    }
};