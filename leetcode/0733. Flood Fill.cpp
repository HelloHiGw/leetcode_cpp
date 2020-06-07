class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        if (image[sr][sc] == newColor) return image;
        vector<vector<int>> dirs = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
        dfs(sr, sc, image, dirs, image[sr][sc], newColor);
        return image;
    }
    
private:
    void dfs(int x, int y, vector<vector<int>> &image, vector<vector<int>> &dirs, int color, int newColor) {
        if (x < 0 || x == image.size() || y < 0 || y == image[0].size() || image[x][y] != color) return;
        image[x][y] = newColor;
        for (auto &d : dirs) {
            int nx = x + d[0], ny = y + d[1];
            dfs(nx, ny, image, dirs, color, newColor);
        }
    }

};


// class Solution {
// public:
//     vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
//         if (image[sr][sc] == newColor) return image;
//         vector<vector<int>> dirs = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};        
//         int color = image[sr][sc];
        
//         queue<pair<int, int>> que;
//         que.push({sr, sc});
        
//         while(!que.empty()) {
//             int x = que.front().first, y = que.front().second;
//             que.pop();
//             image[x][y] = newColor;
//             for (auto &d : dirs) {
//                 int nx = x + d[0], ny = y + d[1];
//                 if (isValid(nx, ny, image, color)) {
//                     que.push({nx, ny});
//                 }
//             }
//         }
        
//         return image;
//     }
    
// private:
//     bool isValid(int x, int y, vector<vector<int>> &image, int color) {
//         return x >= 0 && x < image.size() && y >= 0 && y < image[0].size() && image[x][y] == color;
//     }
// };


