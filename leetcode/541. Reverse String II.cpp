class Solution {
public:
    string reverseStr(string s, int k) {
        string res;
        for (int i = 0; i < s.size(); i += 2 * k) {
            for (int j = min(i + k - 1, (int)s.size() - 1); j >= i; --j) {
                res += s[j];
            }
            if (i + k < s.size()) {
                res += s.substr(i + k, k);
            }
        }
        return res;
    }
};