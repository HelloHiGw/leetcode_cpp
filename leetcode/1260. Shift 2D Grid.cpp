class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        int rows = grid.size(), cols = grid[0].size();
        k %= rows * cols;
        vector<vector<int>> res(rows, vector<int>(cols));
        int num = k;
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                int rowIdx = (num / cols) % rows;
                int colIdx = num % cols;
                res[rowIdx][colIdx] = grid[i][j];
                ++num;
            }
        }
        return res;
    }
};