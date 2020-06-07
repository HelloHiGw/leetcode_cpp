/*
every test cases will run in seperate instances.
I mean to put hashmap outside the function, so it can be reused. 
So my solution will have O(1) average time.

The memory will be released when the instance goes away.So no worry about it.
Leetcode runs different each test cases with new instances. 
(I had an impression it didn't but not sure)
We can easily test it by adding a global counter in the class.

*/
class Solution {
public:
    double soupServings(int N) {
        if (N > 4800) return 1;
        N = (N + 24) / 25;
        return dfs(N, N);
    }
    
private:
    // reused for several test cases of this instance
    // cannot use vector<vector<double>> (200, vector<double>(200)), it reports error
    double memo[200][200];  
    
    double dfs(int a, int b) {
        if (a <= 0 && b <= 0) return 0.5;
        if (a <= 0) return 1;
        if (b <= 0) return 0;
        if (memo[a][b] > 0) return memo[a][b];
        return memo[a][b] = 0.25 * (dfs(a - 4, b) + dfs(a -3, b- 1) + dfs(a - 2, b - 2) + dfs(a - 1, b - 3));
    }
};


/*
1 serving = 25ml.
If the left part is less than 25ml, it is still considered as one serving.
so we need ceil(N / 25.0)

by doing so, we can save time, because soupServing(53) and soupServing(54) is the same
answer, we do not need to run it twice

complexity
time O(N ^ 2), O(N ^ 2) states, O(4) for each state
space O(N ^ 2)
*/

class Solution {
public:
    double soupServings(int N) {
        if (N > 4800) return 1;
        N = (N + 24) / 25;
        // (N + 24) / 25 = ceil(N / 25.0)
        
        vector<vector<double>> memo(N + 1, vector<double>(N + 1, -1));
        return dfs(N, N, memo);
    }
    
private:
    double dfs(int a, int b, vector<vector<double>>& memo) {
        if (a <= 0 && b <= 0) return 0.5;
        if (a <= 0) return 1;
        if (b <= 0) return 0;
        if (memo[a][b] != -1) return memo[a][b];
        return memo[a][b] = 0.25 * (dfs(a - 4, b, memo) + dfs(a -3, b- 1, memo) + dfs(a - 2, b - 2, memo) + dfs(a - 1, b - 3, memo));
    }
};


class Solution {
public:
    double soupServings(int N) {
        if (N > 4800) return 1;
        N = (N + 24) / 25;  // ceil
        vector<vector<double>> dp(N + 1, vector<double>(N + 1, 0));
        
        dp[0][0] = 0.5;
        for (int j = 1; j <= N; ++j) {
            dp[0][j] = 1;
        }
        
        for (int i = 1; i <= N; ++i) {
            for (int j = 1; j <= N; ++j) {
                dp[i][j] = 0.25 * (find(i - 4, j, dp) + find(i - 3, j - 1, dp) + find(i - 2, j - 2, dp) + find(i - 1, j - 3, dp));
            }
        }
        
        return dp[N][N];
    }

private:
    double find(int i, int j, vector<vector<double>>& dp) {
        // less than 0, set to 0
        if (i < 0) i = 0;
        if (j < 0) j = 0;
        return dp[i][j];
    }
};
