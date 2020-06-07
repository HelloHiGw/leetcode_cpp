class Solution {
public:
    int lengthOfLastWord(string s) {
        int len = 0;
        while (s.back() == ' ') s.pop_back();
        for (int i = s.size() - 1; i >= 0; --i) {
            if (s[i] == ' ') break;
            len ++;
        }
        return len;
    }
};