class Solution {
public:
    string reverseWords(string s) {
        string res;
        for (int i = 0, j = 0; i < s.size(); i = j + 1) {
            j = i;
            while (j < s.size() && s[j] != ' ') ++j;
            string str = s.substr(i, j - i);
            reverse(str.begin(), str.end());
            res += str;
            if (j != s.size()) res += ' ';
        }
        return res;
    }
};