class Solution {
public:
    string convert(string s, int numRows) {
        vector<string> v(numRows);
        int i = 0;
        while (i < s.size()) {
            for (int j = 0; j < numRows && i < s.size(); ++j) {
                v[j].push_back(s[i++]);
            }
            for (int j = numRows - 2; j >= 1 && i < s.size(); --j) {
                v[j].push_back(s[i++]);
            }
        }
        string res;
        for (string s : v) res += s;
        return res;
    }
};