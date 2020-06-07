// class Solution {
// public:
//     int findJudge(int N, vector<vector<int>>& trust) {
//         vector<int> outD(N + 1), inD(N + 1);
//         for (auto &v : trust) {
//             ++outD[v[0]];
//             ++inD[v[1]];
//         }
//         for (int i = 1; i <= N; ++i) {
//             if (inD[i] == N - 1 && outD[i] == 0) return i;
//         }
//         return -1;
//     }
// };

class Solution {
public:
    int findJudge(int N, vector<vector<int>>& trust) {
        vector<int> degree(N + 1);
        for (auto &v : trust) {
            --degree[v[0]];
            ++degree[v[1]];
        }
        for (int i = 1; i <= N; ++i) {
            if (degree[i] == N - 1) return i;
        }
        return -1;
    }
};