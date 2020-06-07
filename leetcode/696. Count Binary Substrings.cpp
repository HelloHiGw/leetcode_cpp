class Solution {
public:
    int countBinarySubstrings(string s) {
        int pre = 0, curr = 1, res = 0;
        for (int i = 1; i < s.size(); ++i) {
            if (s[i] == s[i - 1]) {
                ++curr;
            } else {
                res += min(pre, curr);
                pre = curr;
                curr = 1;
            }
        }
        return res + min(pre, curr);
    }
};