class Solution {
public:
    vector<vector<int>> spiralMatrixIII(int R, int C, int r0, int c0) {
        vector<vector<int>> dirs {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        vector<vector<int>> res;
        int x = r0, y = c0;
        int d = 0, steps = 0;  // move <steps> steps in the <d> direction
        res.push_back({x, y});  // push_back ro co for calculating len convenience
        while (res.size() < R * C) {
            if (d == 0 || d == 2) ++steps;  // when move east or west, the length of path need plus 1
            for (int i = 0; i < steps; ++i) {
                x += dirs[d][0];
                y += dirs[d][1];
                if (x >= 0 && x < R && y >= 0 && y < C) res.push_back({x, y}); // valid x y
            }
            d = (d + 1) % 4;
        }
        return res;
    }
};