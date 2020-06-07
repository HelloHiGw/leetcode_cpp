class Solution {
public:
    int compress(vector<char>& chars) {
        int res = 0;
        for (int i = 0, j = 0; i < chars.size(); i = j) {
            while (j < chars.size() && chars[i] == chars[j]) ++j;
            chars[res++] = chars[i];
            if (j - i == 1) continue;
            string s = to_string(j - i);
            for (int k = 0; k < s.size(); ++k) {
                chars[res++] = s[k];
            }
        }
        return res;
    }
};