class Solution {
public:
    int getMaximumGold(vector<vector<int>>& grid) {
        vector<vector<int>> dirs = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
        int res = 0;
        for (int i = 0; i < grid.size(); ++i) {
            for (int j = 0; j < grid[0].size(); ++j) {
                if (grid[i][j]) backtrack(i, j, grid, dirs, 0, res);
            }
        }
        return res;
    }
    
    void backtrack(int i, int j, vector<vector<int>>& grid, vector<vector<int>>& dirs, int curr, int& res) {
        res = max(curr, res);
        if (i < 0 || i == grid.size() || j < 0 || j == grid[0].size() || grid[i][j] == 0) return;
        int val = grid[i][j];
        grid[i][j] = 0;  // set 0 as visited
        for (int k = 0; k < dirs.size(); ++k) {
            backtrack(i + dirs[k][0], j + dirs[k][1], grid, dirs, curr + val, res);
        }
        grid[i][j] = val;
    }
};

// Time: O(k * 4 ^ k + m * n)  
// k is number of cells containing gold, for every cell the time complexity is 4 ^ k 
// (4叉树， path length is at most k)
// m * n is in main function accessing every grid element