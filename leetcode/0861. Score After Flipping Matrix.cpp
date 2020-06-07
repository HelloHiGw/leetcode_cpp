class Solution {
public:
    int matrixScore(vector<vector<int>>& A) {
        int m = A.size(), n = A[0].size();
        int res = m * (1 << (n - 1));
        for (int j = 1; j < n; ++j) {
            int count = 0;
            for (int i = 0; i < m; ++i) count += A[i][j] == A[i][0];
            res += max(count, m - count) * (1 << (n - j - 1));
        }
        return res;
    }
};

/*
A[i][0] is worth 1 << (N - 1) points, more than the sum of (A[i][1] + .. + A[i][N-1]).
We need to toggle all A[i][0] to 1, here I toggle all lines for A[i][0] = 0.

A[i][j] is worth 1 << (N - 1 - j)
For every col, I count the current number of 1s.
After step 1, A[i][j] becomes 1 if A[i][j] == A[i][0].
if M - cur > cur, we can toggle this column to get more 1s.
max(M, M - cur) will be the maximum number of 1s that we can get.

we flip A[i][0] to 1, but we do not change it in A
i.e. if A[i][j] == A[i][0], A[i][j] is 1 (if we change A)
so count is the number of 1s in current column, if 0s > 1s, we flip current column
i.e. max(count, m - count)


I used a greedy idea here. You have to turn the first col to all 1s.
*/