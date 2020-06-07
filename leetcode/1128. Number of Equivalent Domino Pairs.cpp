class Solution {
public:
    int numEquivDominoPairs(vector<vector<int>>& dominoes) {
        unordered_map<int, int> m;
        int res = 0;
        for (auto v : dominoes) {
            int num = min(v[0], v[1]) * 10 + max(v[0], v[1]);
            res += m[num];
            m[num] += 1; 
        }
        return res;
    }
};