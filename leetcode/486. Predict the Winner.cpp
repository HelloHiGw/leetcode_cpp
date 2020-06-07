/*
minimax
time O(2 ^ n)
space O(n)
*/
class Solution {
public:
    bool PredictTheWinner(vector<int>& nums) {
        return canWin(nums, 0, nums.size() - 1, 0, 0, 1);
    }

private:
    bool canWin(vector<int>& nums, int start, int end, int sum1, int sum2, int player) {
        if (start == end) {
            if (player == 1) {
                return sum1 + nums[start] >= sum2;
            } else {
                return sum2 + nums[start] > sum1;
            }
        }
        
        if (player == 1) {
            // at least one true, return true, otherwise return false
            return !canWin(nums, start, end - 1, sum1 + nums[end], sum2, 2) || !canWin(nums, start + 1, end, sum1 + nums[start], sum2, 2);
        } else {
            return !canWin(nums, start, end - 1, sum1, sum2 + nums[end], 1) || !canWin(nums, start + 1, end, sum1, sum2 + nums[start], 1);
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
    bool PredictTheWinner(vector<int>& nums) {
        int n = nums.size();
        
        // this concise state of the problem is really hard to figure out...
        vector<vector<int>> memo(n, vector<int>(n, -1));
        return canWin(nums, 0, n - 1, memo) >= 0;
    }

private:
    int canWin(vector<int>& nums, int start, int end, vector<vector<int>>& memo) {
        if (start == end) return nums[start];
        if (memo[start][end] != -1) return memo[start][end];
        
        int curr = max(nums[start] - canWin(nums, start + 1, end, memo), nums[end] - canWin(nums, start, end - 1, memo));
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
    bool PredictTheWinner(vector<int>& nums) {
        
        int n = nums.size();
        vector<vector<int>> dp(n, vector<int>(n, -1));
        
        for (int i = n - 1; i >= 0; --i) { 
            dp[i][i] = nums[i];
            for (int j = i + 1; j < n; ++j) {
                dp[i][j] = max(nums[i] - dp[i + 1][j], nums[j] - dp[i][j - 1]);
            }
        }
        
        // for (int i = 0; i < n; ++i) dp[i][i] = nums[i];  // the same as following
        // for (int l = 2; l <= n; ++l) {  
        //     for (int i = 0, j = l - 1; j < n; ++i, ++j) {
        //         dp[i][j] = max(nums[i] - dp[i + 1][j], nums[j] - dp[i][j - 1]);
        //     }
        // }
        
        return dp[0][n - 1] >= 0;
    }
};


/*
dp
time O(n ^ 2)
space O(n)
*/
class Solution {
public:
    bool PredictTheWinner(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n, -1);
        
        for (int i = n - 1; i >= 0; --i) {
            dp[i] = nums[i];
            for (int j = i + 1; j < n; ++j) {
                dp[j] = max(nums[i] - dp[j], nums[j] - dp[j - 1]);
            }
        }
        
        return dp[n - 1] >= 0;
    }
};



