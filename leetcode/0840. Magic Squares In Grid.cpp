// class Solution {
// public:
//     int numMagicSquaresInside(vector<vector<int>>& grid) {
//         int res = 0;
//         for (int i = 1; i < grid.size() - 1; ++i) {
//             for (int j = 1; j < grid[0].size() - 1; ++j) {
//                 res += judge(grid, i, j) ? 1 : 0;
//             }
//         }
//         return res;
//     }
    
//     bool judge(vector<vector<int>>& grid, int x, int y) {
//         set<int> st;
//         for (int i = -1; i < 2; ++i) {
//             for (int j = -1; j < 2; ++j) {
//                 if (st.find(grid[x + i][y + j]) != st.end() || grid[x + i][y + j] < 1 || grid[x + i][y + j] > 9) return false;
//                 st.insert(grid[x + i][y + j]);
//             }
//         }
        
//         int sum = -1;
//         for (int i = -1; i < 2; ++i) {
//             int currSum = 0;
//             for (int j = -1; j < 2; ++j) {
//                 currSum += grid[x + i][y + j];
//             }
//             if (sum == -1) {
//                 sum = currSum;
//             } else if (sum != currSum) {
//                 return false;
//             }
//         }
//         for (int i = -1; i < 2; ++i) {
//             int currSum = 0;
//             for (int j = -1; j < 2; ++j) {
//                 currSum += grid[x + j][y + i];
//             }
//             if (sum != currSum) return false;
//         }
//         if (grid[x - 1][y - 1] + grid[x][y] + grid[x + 1][y + 1] != sum) return false;
//         if (grid[x - 1][y + 1] + grid[x][y] + grid[x + 1][y - 1] != sum) return false;
//         return true;
//     }
// };


class Solution {
public:
    int numMagicSquaresInside(vector<vector<int>>& grid) {
        int res = 0;
        for (int i = 1; i < grid.size() - 1; ++i) {
            for (int j = 1; j < grid[0].size() - 1; ++j) {
                res += judge(grid, i, j) ? 1 : 0;
            }
        }
        return res;
    }
    
    bool judge(vector<vector<int>>& grid, int i, int j) {
        if (grid[i][j] != 5) return false;
        if (grid[i - 1][j - 1] % 2 == 1 || grid[i - 1][j + 1] % 2 == 1 || grid[i + 1][j - 1] % 2 == 1 || grid[i + 1][j + 1] % 2 == 1) return false;
        string str = to_string(grid[i - 1][j - 1]) + to_string(grid[i - 1][j]) + to_string(grid[i - 1][j + 1]) + to_string(grid[i][j + 1]) + to_string(grid[i + 1][j + 1]) + to_string(grid[i + 1][j]) + to_string(grid[i + 1][j - 1]) + to_string(grid[i][j - 1]);
        string s1 = "4381672943816729", s2 = "4927618349276183";
        return s1.find(str) != string::npos || s2.find(str) != string::npos;
    }
};