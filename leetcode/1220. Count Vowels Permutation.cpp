class Solution {
public:
    int countVowelPermutation(int n) {
        // dp[i][0], number of string ending with 'a'
        // dp[i][4], number of string ending with 'u'
        const int MOD = 1e9 + 7;
        vector<vector<long>> dp(n + 1, vector<long>(5, 0));
        for (int i = 0; i < 5; ++i) dp[1][i] = 1;
        
        for (int i = 2; i <= n; ++i) {
            dp[i][0] = (dp[i - 1][1] + dp[i - 1][2] + dp[i - 1][4]) % MOD;
            dp[i][1] = (dp[i - 1][0] + dp[i - 1][2]) % MOD;
            dp[i][2] = (dp[i - 1][1] + dp[i - 1][3]) % MOD;
            dp[i][3] = dp[i - 1][2];
            dp[i][4] = (dp[i - 1][2] + dp[i - 1][3]) % MOD;
        }

        int res = 0;
        for (int val : dp[n]) {
            res = (res + val) % MOD;
        }
        return res;
    }
};


class Solution {
public:
    int countVowelPermutation(int n) {
        vector<vector<long>> res = {{1, 1, 1, 1, 1}};
        vector<vector<long>> matrix = {
            {0, 1, 0, 0, 0},
            {1, 0, 1, 0, 0},
            {1, 1, 0, 1, 1},
            {0, 0, 1, 0, 1}, 
            {1, 0, 0, 0, 0}
        };
        
        --n;
        while (n) {
            if (n & 1) res = matrixMultiplication(res, matrix);
            matrix = matrixMultiplication(matrix, matrix);
            n >>= 1;
        }
        
        int cnt = 0;
        for (auto& val : res[0]) {
            cnt = (cnt + val) % MOD;
        }
        return cnt;
    }

private:
    const int MOD = 1e9 + 7;
    
    vector<vector<long>> matrixMultiplication(vector<vector<long>>& m1, vector<vector<long>>& m2) {
        int r = m1.size(), c = m2[0].size(), n = m1[0].size();
        vector<vector<long>> res(r, vector<long>(c));
        
        for (int i = 0; i < r; ++i) {
            for (int j = 0; j < c; ++j) {
                for (int k = 0; k < n; ++k) {
                    res[i][j] = (res[i][j] + m1[i][k] * m2[k][j]) % MOD;
                }
            }
        }
        
        return res;
    }
};


