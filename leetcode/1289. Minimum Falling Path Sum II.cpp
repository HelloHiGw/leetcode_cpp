/*
m = n
time O(n ^ 3)
space O(n^2)
*/

class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& arr) {
        int m = arr.size(), n = arr[0].size();
        // dp[i][j], the minimum sum falling to arr[i][j]
        vector<vector<int>> dp(m, vector<int>(n, 0));
        dp[0] = arr[0];
        
        for (int i = 1; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                // find the minimum dp[i - 1][k] (k != j)
                int minValue = INT_MAX;
                for (int k = 0; k < n; ++k) {
                    if (k == j) continue;
                    minValue = min(minValue, dp[i - 1][k]);
                }
                
                dp[i][j] = minValue + arr[i][j];
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
m = n
time O(n ^ 3)
space O(n)
*/

class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& arr) {
        int m = arr.size(), n = arr[0].size();
        vector<int> prev = arr[0], curr(n, 0);
        
        for (int i = 1; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                int minValue = INT_MAX;
                for (int k = 0; k < n; ++k) {
                    if (k == j) continue;
                    minValue = min(minValue, prev[k]);
                }
                curr[j] = minValue + arr[i][j];
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


/*
m = n
time O(n ^ 2)
space O(n)
*/

class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& arr) {
        int m = arr.size(), n = arr[0].size();
        vector<int> dp(n, 0);
        
        // we have to record pos of firstMin
        // because using O(n) dp, dp[i - 1] is lost
        // if you use prev, do not need pos
        // int minimum == prev[j] == firstMin ? secondMin : firstMin;
        int firstMin = 0, secondMin = 0, pos = -1; 
        
        for (int i = 0; i < m; ++i) {
            int firstMinI = INT_MAX, secondMinI = INT_MAX, posI = -1;
            for (int j = 0; j < n; ++j) {
                int minimum = j == pos ? secondMin : firstMin;
                dp[j] = minimum + arr[i][j];
                
                if (dp[j] < firstMinI) {
                    secondMinI = firstMinI;
                    firstMinI = dp[j];
                    posI = j;
                } else if (dp[j] < secondMinI) {
                    secondMinI = dp[j];
                }
            }
            
            firstMin = firstMinI, secondMin = secondMinI, pos = posI;
        }
        
        int res = INT_MAX;
        for (int j = 0; j < n; ++j) {
            res = min(res, dp[j]);
        }
        return res;
    }
};