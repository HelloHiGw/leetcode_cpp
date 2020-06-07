/*
time O(10 * N * 3), 3 is the max size of neis[i]
space O(N * 10)
*/
class Solution {
public:
    int knightDialer(int N) {
        vector<vector<int>> neis = {{4, 6}, {6, 8}, {7, 9}, {4, 8}, {3, 9, 0}, {}, {1, 7, 0}, {2, 6}, {1, 3}, {2, 4}, {4, 6}};  // i and nei[i] and jump to each other
        vector<vector<int>> memo(N + 1, vector<int>(10, -1));
        int res = 0;
                
        for (int i = 0; i < 10; ++i) {
            res = (res + dfs(i, N, neis, memo)) % MOD;
        }
        
        return res;
    }
    
private:
    const int MOD = 1e9 + 7;
    
    int dfs(int num, int N, vector<vector<int>>& neis, vector<vector<int>>& memo) {
        if (N == 1) return 1;
        if (memo[N][num] != -1) return memo[N][num];
        int count = 0;
        for (int nei : neis[num]) {
            count = (count + dfs(nei, N - 1, neis, memo)) % MOD;
        }
        return memo[N][num] = count;
    }
};


/*
time O(10 * N * 3)
space O(N * 10)
the same as above
*/
class Solution {
public:
    int knightDialer(int N) {
        vector<vector<int>> neis = {{4, 6}, {6, 8}, {7, 9}, {4, 8}, {3, 9, 0}, {}, {1, 7, 0}, {2, 6}, {1, 3}, {2, 4}, {4, 6}};  // i and nei[i] and jump to each other
        vector<vector<int>> memo(N + 1, vector<int>(10, 0));
        int res = 0;
        constexpr int MOD = 1e9 + 7;
        
        for (int i = 0; i < 10; ++i) memo[1][i] = 1;
        
        for (int n = 2; n <= N; ++n) {
            for (int i = 0; i < 10; ++i) {
                for (int nei : neis[i]) {
                    memo[n][i] = (memo[n][i] + memo[n - 1][nei]) % MOD;
                }
            }
        }
        
        for (int i = 0; i < 10; ++i) {
            res = (res + memo[N][i]) % MOD;
        }
        
        return res;
    }
};


/*
time O(10 * N * 3)
space O(1)
*/
class Solution {
public:
    int knightDialer(int N) {
        vector<vector<int>> neis = {{4, 6}, {6, 8}, {7, 9}, {4, 8}, {3, 9, 0}, {}, {1, 7, 0}, {2, 6}, {1, 3}, {2, 4}, {4, 6}};  // i and nei[i] and jump to each other
        vector<int> pre(10, 1), curr(10, 0);
        int res = 0;
        constexpr int MOD = 1e9 + 7;
    
        for (int n = 2; n <= N; ++n) {
            for (int i = 0; i < 10; ++i) {
                curr[i] = 0;
                for (int nei : neis[i]) {
                    curr[i] = (curr[i] + pre[nei]) % MOD;
                }
            }
            swap(pre, curr);
        }
        
        for (int i = 0; i < 10; ++i) {
            res = (res + pre[i]) % MOD;
        }
        
        return res;
    }
};



/*
time O(logN)
space O(1)
*/
class Solution {
public:
    int knightDialer(int N) {
        if (N == 1) return 10;
        constexpr int MOD = 1e9 + 7;
        --N;  // simulate you will konw, if N = 2, path length = 1
        
        // matrix[i][j] denotes the number of path from i to j with length of 1, 
        // matrix^n [i][j] denotes the number of path from i to j with length of n
        // int will overflow for matrix multiply m1[i][k] * m2[k][j]
        vector<vector<long>> matrix = { 
            {0, 0, 0, 0, 1, 0, 1, 0, 0, 0},
            {0, 0, 0, 0, 0, 0, 1, 0, 1, 0},
            {0, 0, 0, 0, 0, 0, 0, 1, 0, 1},
            {0, 0, 0, 0, 1, 0, 0, 0, 1, 0},
            {1, 0, 0, 1, 0, 0, 0, 0, 0, 1},
            {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
            {1, 1, 0, 0, 0, 0, 0, 1, 0, 0},                     
            {0, 0, 1, 0, 0, 0, 1, 0, 0, 0},
            {0, 1, 0, 1, 0, 0, 0, 0, 0, 0},
            {0, 0, 1, 0, 1, 0, 0, 0, 0, 0},            
        };
        vector<vector<long>> resultMatrix(10, vector<long>(10));
        
        for (int i = 0; i < 10; ++i) {
            resultMatrix[i][i] = 1;
        }
        
        while (N) {
            if (N & 1) resultMatrix = multiplyMatrix(resultMatrix, matrix);
            matrix = multiplyMatrix(matrix, matrix);
            N >>= 1;
        }
        
        int res = 0;
        for (int i = 0; i < 10; ++i) {
            for (int j = 0; j < 10; ++j) {
                res = (res + resultMatrix[i][j]) % MOD;
            }
        }
        
        return res;
    }
    
private:
    const int MOD = 1e9 + 7;
    
    vector<vector<long>> multiplyMatrix(vector<vector<long>>& m1, vector<vector<long>>& m2) {
        int r = m1.size(), c = m2[0].size();
        int n = m1[0].size();
        vector<vector<long>> res(r, vector<long>(c));
        
        for (int i = 0; i < r; ++i) {
            for (int j = 0; j < c; ++j) {
                for (int k = 0; k < n; ++k) {
                    res[i][j] = (res[i][j] + ((m1[i][k] * m2[k][j]) % MOD)) % MOD;
                }
            }
        }
        return res;
    }
};
