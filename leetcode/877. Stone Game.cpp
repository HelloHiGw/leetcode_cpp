/*
minimax
time O(2 ^ n)
space O(n)

TLE brute force
*/
class Solution {
public:
    bool stoneGame(vector<int>& piles) {
        return dfs(0, piles.size() - 1, piles, 0, 0, 'A');
    }
    
private:
    bool dfs(int start, int end, vector<int>& piles, int sumA, int sumL, char player) {
        if (start == end) {
            if (player == 'A') {
                return piles[start] + sumA > sumL;
            } else {
                return piles[start] + sumL > sumA;
            }
        }
        
        if (player == 'A') {
            return !dfs(start + 1, end, piles, sumA + piles[start], sumL, 'L')  ||
                   !dfs(start, end - 1, piles, sumA + piles[end], sumL, 'L');
        } else {
            return !dfs(start + 1, end, piles, sumA, sumL + piles[start], 'A') ||
                   !dfs(start, end - 1, piles, sumA, sumL + piles[end], 'A');
        }
    }
};


/*
minimax + memo (dfs + memo)
time O(n ^ 2), i don't know, but is should be the same as bottom up dp
space O(n ^ 2)

if you want to use memo, the state of the problem should be start, end, sum1, sum2

after noting that the sum of all numbers is fixed, I realized that it doesn't matter how much 
player 1's total sum is as long as the sum is no less than player 2's sum.

so memo[i][j] saves how much more scores that the first-in-action player will 
get from i to j than the second player (i is start, j is end, j >= i)

Suppose they are picking up numbers from position i to j in the array and it is player A's turn 
to pick the number now. If player A picks position i, player A will earn nums[i] score instantly. 
Then player B will choose from i + 1 to j. 

Please note that dp[i + 1][j] already saves how much more score that the first-in-action player 
will get from i + 1 to j than the second player. So it means that player B will eventually earn 
dp[i + 1][j] more score from i + 1 to j than player A. So if player A picks position i,eventually 
player A will get nums[i] - dp[i + 1][j] more score than player B after they pick up all numbers. 

Similarly, if player A picks position j, player A will earn nums[j] - dp[i][j - 1] more score 
than player B after they pick up all numbers. Since A is smart, A will always choose the max in 
those two options, so:

dp[i][j] = Math.max(nums[i] - dp[i + 1][j], nums[j] - dp[i][j - 1]);
*/
class Solution {
public:
    bool stoneGame(vector<int>& piles) {
        int n = piles.size();
        vector<vector<int>> memo(n, vector<int>(n, -1));
        return canWin(0, n - 1, piles, memo) > 0;
    }
    
private:
    int canWin(int start, int end, vector<int>& piles, vector<vector<int>>& memo) {
        if (start == end) return piles[start];
        if (memo[start][end] != -1) return memo[start][end];
        
        int curr;
        curr = max(piles[start] - canWin(start + 1, end, piles, memo), piles[end] - canWin(start, end - 1, piles, memo));
        return memo[start][end] = curr;
    }
};


/*
dp
time O(n ^ 2)
space O(n ^ 2)
*/
class Solution {
public:
    bool stoneGame(vector<int>& piles) {
        int n = piles.size();
        vector<vector<int>> dp(n, vector<int>(n, 0));

        // for (int i = n - 1; i >= 0; --i) { 
        //     dp[i][i] = nums[i];
        //     for (int j = i + 1; j < n; ++j) {
        //         dp[i][j] = max(nums[i] - dp[i + 1][j], nums[j] - dp[i][j - 1]);
        //     }
        // }

        for (int i = 0; i < n; ++i) dp[i][i] = piles[i];
        for (int l = 2; l <= n; ++l) {
            for (int i = 0, j = l - 1; j < n; ++i, ++j) {
                dp[i][j] = max(piles[i] - dp[i + 1][j], piles[j] - dp[i][j - 1]);
            }
        }

        return dp[0][n - 1] > 0;
    }
};


/*
dp
time O(n ^ 2)
space O(n)
*/
class Solution {
public:
    bool stoneGame(vector<int>& piles) {
        int n = piles.size();
        vector<int> dp(n);
        for (int i = n - 1; i >= 0; --i) {
            dp[i] = piles[i];
            for (int j = i + 1; j < n; ++j) {
                dp[j] = max(piles[i] - dp[j], piles[j] - dp[j - 1]);
            }
        }
        return dp[n - 1] > 0;
    }
};


/*
Here is my understanding:
piles.length is even, which means Alex pick half and Lee pick half. 
So we have many different divisions here.

But to make it simple, we find the fact that sum(piles[even]) and sum(piles[odd]) 
must not be equal.

That's why we want to pick all even indexes or all odd indexes to get the larger half.
And Alex always have the right to choose all even indexes or all odd indexes 
because he starts first.

Then Alex can always to get the larger half.
*/
class Solution {
public:
    bool stoneGame(vector<int>& piles) {
        return true;
    }
};

