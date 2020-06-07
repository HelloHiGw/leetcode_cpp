class Solution {
public:
    int maxNumberOfBalloons(string text) {
        unordered_map<char, int> m;
        for (char ch : text) {
            if (ch == 'b' || ch == 'a' || ch == 'l' || ch == 'o' || ch == 'n') {
                ++m[ch];
            }
        }
        if (m.size() < 5) return 0;
        int res = INT_MAX;
        for (auto it : m) {
            res = min(res, it.first == 'l' || it.first == 'o' ? it.second / 2 : it.second);
        }
        return res;
    }
};