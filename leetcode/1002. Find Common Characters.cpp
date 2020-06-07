class Solution {
public:
    vector<string> commonChars(vector<string>& A) {
        vector<int> res(26, INT_MAX);
        for (string s : A) {
            vector<int> count(26);
            for (int i = 0; i < s.size(); ++i) {
                count[s[i] - 'a'] += 1;
            }
            for (int i = 0; i < 26; ++i) {
                res[i] = min(res[i], count[i]);
            }
        }
        vector<string> v;
        for (char ch = 'a'; ch <= 'z'; ++ch) {
            while (res[ch - 'a'] > 0) {
                v.push_back(string(1, ch));
                res[ch - 'a'] -= 1;
            }
        }
        return v;
    }
};