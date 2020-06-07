// class Solution {
// public:
//     vector<vector<int>> generateMatrix(int n) {
//         vector<vector<int>> res(n, vector<int>(n));
//         int up = 0, down = n - 1;
//         int left = 0, right = n - 1;
//         int curr = 1;
//         while (curr <= n * n) {
//             for (int j = left; j <= right && curr <= n * n; ++j) {
//                 res[up][j] = curr++;
//             }
//             for (int i = up + 1; i <= down - 1 && curr <= n * n; ++i) {
//                 res[i][right] = curr++;
//             }
//             for (int j = right; j >= left && curr <= n * n; --j) {
//                 res[down][j] = curr++;
//             }
//             for (int i = down - 1; i >= up + 1 && curr <= n * n; --i) {
//                 res[i][left] = curr++;
//             }
//             ++up;
//             --down;
//             ++left;
//             --right;
//         }
//         return res;
//     }
// };


class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> dirs {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        vector<vector<int>> res(n, vector<int>(n));
        vector<int> nSteps {n, n - 1};
        int x = 0, y = -1;
        int d = 0;
        int curr = 1;
        while (nSteps[d % 2]) {
            for (int i = 0; i < nSteps[d % 2]; ++i) {
                x += dirs[d][0];
                y += dirs[d][1];
                res[x][y] = curr++;
            }
            --nSteps[d % 2];
            d = (d + 1) % 4;
        }
        return res;
    }
};