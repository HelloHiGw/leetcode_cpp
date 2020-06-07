// class Solution {
// public:
//     int countNegatives(vector<vector<int>>& grid) {
//         return countNeg(grid, grid.size() -  1, grid[0].size() - 1);
//     }
    
//     int countNeg(vector<vector<int>>& grid, int r, int c) {
//         if (r < 0 || c < 0) return 0;
//         if (grid[r][c] >= 0) return 0;
//         int count = 1;
//         for (int i = r - 1; i >= 0 && grid[i][c] < 0; --i) ++count;
//         for (int j = c - 1; j >= 0 && grid[r][j] < 0; --j) ++count;
//         return count + countNeg(grid, r - 1, c - 1);
//     }
// };

class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        int row = grid.size(), col = grid[0].size();
        int r = row - 1, c = 0;
        int count = 0;
        while (r >= 0 && c < col) {
            if (grid[r][c] < 0) {
                count += col - c;
                --r;
            } else {
                ++c;
            }
        }
        return count;
    }
};