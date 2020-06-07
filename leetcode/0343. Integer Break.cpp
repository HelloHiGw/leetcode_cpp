// class Solution {
// public:
//     int integerBreak(int n) {
//         vector<int> dp(n + 1);
//         for (int i = 1; i <= n; ++i) {
//             for (int j = 1; j <= i / 2; ++j) {
//                 dp[i] = max(dp[i], max(j, dp[j]) * max(i - j, dp[i - j]));
//             }
//         }
//         return dp[n];
//     }
// };
/*
let's say i = 8, we are trying to fill dp[8]:if 8 can only be broken into 2 parts, the answer 
could be among 1 * 7, 2 * 6, 3 * 5, 4 * 4... but these numbers can be further broken. 
so we have to compare 1 with dp[1], 7 with dp[7], 2 with dp[2], 6 with dp[6]...etc
*/


class Solution {
public:
    int integerBreak(int n) {
        if (n == 2) return 1;
        if (n == 3) return 2;
        int num3 = n / 3;
        if (n % 3 == 0) {
            return (int)pow(3, num3);
        } else if (n % 3 == 1) {  // special case, change 3 + 1 to 2 + 2, here using 2 twice
            return (int)pow(3, num3 - 1) * 4;
        } else {  // using 2 once
            return (int)pow(3, num3) * 2;
        }
    }
};

/*
If an optimal product contains a factor f >= 4, then you can replace it with factors 2 and f-2 
without losing optimality, as 2*(f-2) = 2f-4 >= f. So you never need a factor greater than or 
equal to 4, meaning you only need factors 1, 2 and 3 (and 1 is of course wasteful and you'd 
only use it for n=2 and n=3, where it's needed).

So we now just need to write n = a * 3 + b * 2 such that P = (3^a) * (2^b) is maximized
3 * (f - 3) >= 2 * (f - 2) > f for f >= 5 so you should use 3 to decode f >= 5 and 2 to decode f = 4
3*3 is simply better than 2*2*2, so you'd never use 2 more than twice.
*/