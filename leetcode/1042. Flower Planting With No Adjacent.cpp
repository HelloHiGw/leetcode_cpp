class Solution {
public:
    vector<int> gardenNoAdj(int N, vector<vector<int>>& paths) {
        vector<vector<int>> G(N);
        for (auto &p : paths) {
            G[p[0] - 1].push_back(p[1] - 1);  // res is from 0 to N-1, for accessing res convenience
            G[p[1] - 1].push_back(p[0] - 1);
        }
        vector<int> res(N);
        for (int i = 0; i < N; ++i) {
            vector<bool> used(5, false);  // color used
            for (int nei : G[i]) used[res[nei]] = true;  // set the color of neighbor as used, if color of neighbor is none, used[0] = true, doest not matter 1 to 4
            for (int j = 1; j < 5; ++j) {
                if (!used[j]) {
                    res[i] = j;
                    break;
                }
            }
        }
        return res;
    }
};