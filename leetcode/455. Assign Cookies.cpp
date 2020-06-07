// class Solution {
// public:
//     int findContentChildren(vector<int>& g, vector<int>& s) {
//         sort(g.begin(), g.end());
//         sort(s.begin(), s.end());
//         int res = 0, i = 0;
//         for (int gf : g) {
//             while (i < s.size() && s[i] < gf) ++i;
//             if (i == s.size()) break;
//             ++i;
//             ++res;
//         }
//         return res;
//     }
// };

class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());
        int i = 0;
        for (int j = 0; j < s.size() && i < g.size(); ++j) {
            if (s[j] >= g[i]) ++i;
        }
        return i;
    }
};