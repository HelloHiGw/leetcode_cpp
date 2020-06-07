// class Solution {
// public:
//     vector<int> spiralOrder(vector<vector<int>>& matrix) {
//         if (matrix.empty() || matrix[0].empty()) return {};
//         int m = matrix.size(), n = matrix[0].size();
//         int up = 0, down = m - 1;
//         int left = 0, right = n - 1;
//         vector<int> res;
//         while (res.size() < m * n) {
//             for (int j = left; j <= right && res.size() < m * n; ++j) {
//                 res.push_back(matrix[up][j]);
//             }
//             for (int i = up + 1; i <= down - 1 && res.size() < m * n; ++i) {
//                 res.push_back(matrix[i][right]);
//             }
//             for (int j = right; j >= left && res.size() < m * n; --j) {
//                 res.push_back(matrix[down][j]);
//             }
//             for (int i = down - 1; i >= up + 1 && res.size() < m * n; --i) {
//                 res.push_back(matrix[i][left]);
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
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        if (matrix.empty() || matrix[0].empty()) return {};
        vector<vector<int>> dirs {{0, 1}, {1, 0}, {0, -1}, {-1, 0}}; // right down left up
        vector<int> res;
        vector<int> nSteps {n, m - 1};  // horizontal and vertical steps
        int m = matrix.size(), n = matrix[0].size();
        int x = 0, y = -1;  // initial position
        int d = 0;
        while (nSteps[d % 2]) {
            for (int i = 0; i < nSteps[d % 2]; ++i) {
                x += dirs[d][0];
                y += dirs[d][1];
                res.push_back(matrix[x][y]);
            }
            --nSteps[d % 2]; // 3(1, 2, 3) 2(4, 5) 2(6, 7) 1(8) 1(9) for 3 * 3
            d = (d + 1) % 4;   
        }
        return res;
    }
};
