class Solution {
public:
    string freqAlphabets(string s) {
        string res;
        int i = s.size() - 1;
        while (i >= 0) {
            if (s[i] == '#') {
                int num = stoi(s.substr(i - 2, 2));
                res += 'a' + num - 1;
                i -= 3;
            } else {
                res += 'a' + s[i] - '1';
                -- i;
            }
        }
        reverse(res.begin(), res.end());
        return res;
    }
};