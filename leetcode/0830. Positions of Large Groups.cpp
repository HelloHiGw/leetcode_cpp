class Solution {
public:
    vector<vector<int>> largeGroupPositions(string S) {
        vector<vector<int>> res;
        for (int i = 0, j = 0; i < S.size(); i = j) {
            while (j < S.size() && S[i] == S[j]) ++j;
            if (j - i >= 3) {
                res.push_back({i, j - 1});
            }
        }
        return res;
    }
};