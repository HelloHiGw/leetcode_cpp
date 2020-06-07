class Solution {
public:
    string sortString(string s) {
        vector<int> cnt(26);
        for (char ch : s) {
            cnt[ch - 'a'] += 1;
        }
        string res;
        while (res.size() < s.size()) {
            for (int i = 0; i < 26; ++i) {
                if (cnt[i]) {
                    res += (char)(i + 'a');
                    --cnt[i];
                }
            }
            for (int i = 25; i >= 0; --i) {
                if (cnt[i]) {
                    res += (char)(i + 'a');
                    --cnt[i];
                }
            }
        }
        return res;
    }
};