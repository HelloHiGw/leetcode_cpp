/*
Two pattern for each row, 121 and 123.
121, the first color same as the third in a row.
123, one row has three different colors.

We consider the state of the first row,
pattern 121: 121, 131, 212, 232, 313, 323.
pattern 123: 123, 132, 213, 231, 312, 321.
So we initialize a121 = 6, a123 = 6.

We consider the next possible for each pattern:
Patter 121 can be followed by: 212, 213, 232, 312, 313
Patter 123 can be followed by: 212, 231, 312, 232

121 => three 121, two 123
123 => two 121, two 123

So we can write this dynamic programming transform equation:
b121 = a121 * 3 + a123 * 2
b123 = a121 * 2 + a123 * 2
*/
class Solution {
public:
    int numOfWays(int n) {
        long a121 = 6, a123 = 6;
        long b121, b123;
        constexpr int MOD = 1e9 + 7;
        for (int i = 0; i < n - 1; ++i) {
            b121 = (3 * a121 + 2 * a123) % MOD;
            b123 = (2 * a121 + 2 * a123) % MOD;
            a121 = b121;
            a123 = b123;
        }
        return (a121 + a123) % MOD;
    }
};


/*
it seems not a dp problem ? 
because no overlapping subproblem
do not need memo to recored the answer of subproblem
*/
class Solution {
public:
    int numOfWays(int n) {
        auto p = dfs(n);
        return (p.first + p.second) % MOD;
        
    }
    
private:
    const int MOD = 1e9 + 7;
    
    pair<long, long> dfs(int n) {
        if (n == 1) return {6, 6};
        auto prev = dfs(n - 1);
        long a121 = (prev.first * 3 + prev.second * 2) % MOD;
        long a123 = (prev.first * 2 + prev.second * 2) % MOD;
        return {a121, a123};
    }
};


class Solution {
public:
    int numOfWays(int n) {
        vector<vector<long>> res = {{6, 6}};
        vector<vector<long>> M = {{3, 2}, {2, 2}};  // the first row denotes b121 = a121 * 3 + a123 * 2
        
        // we want res * M ^ (n - 1), here res is equal to the unit matrix in fast exponential
        --n;
        while (n) {
            if (n & 1) res = matrixMultiplication(res, M);
            M = matrixMultiplication(M, M);
            n >>= 1;
        }
        return (res[0][0] + res[0][1]) % MOD;
    }
    
private:
    const int MOD = 1e9 + 7;
    
    vector<vector<long>> matrixMultiplication(vector<vector<long>>& m1, vector<vector<long>>& m2) {
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

