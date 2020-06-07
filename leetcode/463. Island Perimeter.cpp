// class Solution {
// public:
//     int islandPerimeter(vector<vector<int>>& grid) {
//         vector<vector<bool>> visited(grid.size(), vector<bool>(grid[0].size(), false));
//         vector<vector<int>> dirs = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
//         for (int i = 0; i < grid.size(); ++i) {
//             for (int j = 0; j < grid[0].size(); ++j) {
//                 if (grid[i][j] == 1) return dfs(i, j, grid, visited, dirs);
//             }
//         }
//         return 0;
//     }
    
// private:
//     bool isLand(int i, int j, vector<vector<int>>& grid) {
//         return i >= 0 && i < grid.size() && j >= 0 && j < grid[0].size() && grid[i][j] == 1;
//     }
    
//     int dfs(int i, int j, vector<vector<int>>& grid, vector<vector<bool>>& visited, vector<vector<int>>& dirs) {
//         if (i < 0 || i == grid.size() || j < 0 || j == grid[0].size() || grid[i][j] == 0 || visited[i][j]) return 0;
//         visited[i][j] = true;
//         int res = 4;
//         for (auto& d : dirs) {
//             int ni = i + d[0], nj = j + d[1];
//             res -= isLand(ni, nj, grid);
//             res += dfs(ni, nj, grid, visited, dirs);
//         }
//         return res;
//     }
// };

/*
Only check right and down, because left and up will get checked by a previous element.
A neighbor subtracts a side from the perimeter. But since only count right and down, we 
have to double count. thus -2*neighbors.
(since every adjacent islands made two sides disappeared)
*/
class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        int lands = 0, neighbors = 0;
        for (int i = 0; i < grid.size(); ++i) {
            for (int j = 0; j < grid[0].size(); ++j) {
                if (grid[i][j] == 1) {
                    ++lands;
                    if (i && grid[i - 1][j] == 1) ++neighbors;
                    if (j && grid[i][j - 1] == 1) ++neighbors;
                }
            }
        }
        return 4 * lands - 2 * neighbors;
    }
};