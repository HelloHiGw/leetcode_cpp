// class Solution {
// public:
//     vector<vector<int>> allCellsDistOrder(int R, int C, int r0, int c0) {
//         vector<vector<int>> res;
//         for (int i = 0; i < R; ++i) {
//             for (int j = 0; j < C; ++j) {
//                 res.push_back({i, j});
//             }
//         }
        
//         sort(res.begin(), res.end(),[&](vector<int>& v1, vector<int>& v2){
//             return abs(v1[0] - r0) + abs(v1[1] - c0) < abs(v2[0] - r0) + abs(v2[1] - c0);
//         });
        
//         return res;
//     }
// };


class Solution {
public:
    vector<vector<int>> allCellsDistOrder(int R, int C, int r0, int c0) {
        vector<vector<bool>> visited(R, vector<bool>(C, false));
        queue<pair<int, int>> que;
        que.push({r0, c0});
        visited[r0][c0] = true;
        
        vector<vector<int>> res;
        vector<vector<int>> dirs = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
        
        while (!que.empty()) {
            for (int i = que.size(); i > 0; --i) {
                int x = que.front().first, y = que.front().second;
                que.pop();
                res.push_back({x, y});
                for (auto& d : dirs) {
                    int nx = x + d[0], ny = y + d[1];
                    if (isValid(nx, ny, R, C, visited)) {
                        que.push({nx, ny});
                        visited[nx][ny] = true;
                    }
                }
            }
        }
        
        return res;
    }
    
private:
    bool isValid(int x, int y, int R, int C, vector<vector<bool>>& visited) {
        return x >= 0 && x < R && y >= 0 && y < C && !visited[x][y];
    }
};