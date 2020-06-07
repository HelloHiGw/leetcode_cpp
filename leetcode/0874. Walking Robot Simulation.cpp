class Solution {
public:
    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
        unordered_map<int, unordered_map<int, bool>> isObstacle;
        for (auto v : obstacles) {
            isObstacle[v[0]][v[1]] = true;
        }
        vector<vector<int>> dirs = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        int d = 0;
        int x = 0, y = 0;
        int res = 0;
        for (int c : commands) {
            if (c == -2) {
                d = (d - 1 + 4) % 4;  // in case of negatives
            } else if (c == -1) {
                d = (d + 1) % 4;
            } else {
                for (int i = 0; i < c; ++i) {
                    x += dirs[d][0];
                    y += dirs[d][1];
                    if (isObstacle[x][y]) {
                        x -= dirs[d][0];
                        y -= dirs[d][1];
                        break;
                    }
                    res = max(res, x * x + y * y);
                }
            }
        }
        return res;
    }
};


// class Solution {
// public:
//     int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
//         unordered_set<string> obs;
//         for (auto v : obstacles) {
//             obs.insert(to_string(v[0]) + " " + to_string(v[1]));
//         }
//         vector<vector<int>> dirs = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
//         int d = 0;
//         int x = 0, y = 0;
//         int res = 0;
//         for (int c : commands) {
//             if (c == -2) {
//                 d = (d - 1 + 4) % 4;  // in case of negatives
//             } else if (c == -1) {
//                 d = (d + 1) % 4;
//             } else {
//                 for (int i = 0; i < c; ++i) {
//                     x += dirs[d][0];
//                     y += dirs[d][1];
//                     if (obs.count(to_string(x) + " " + to_string(y))) {
//                         x -= dirs[d][0];
//                         y -= dirs[d][1];
//                         break;
//                     }
//                     res = max(res, x * x + y * y);
//                 }
//             }
//         }
//         return res;
//     }
// };