/*

The idea is, if we know the max number of unique substrings in p ends with 'a', 'b', ..., 'z', 
then the summary of them is the answer. 

abcd
1 + 2 + 3 + 4
1 a
2 ab b
3 abc bc c
4 abcd bcd cd d
*/

class Solution {
public:
    int findSubstringInWraproundString(string p) {
        vector<int> cnt(26);
        int maxLen = 0;
        for (int i = 0; i < p.size(); ++i) {
            if (i && (p[i] == p[i - 1] + 1 || p[i] == 'a' && p[i - 1] == 'z')) {
                ++maxLen;
            } else {
                maxLen = 1;
            }
            int index = p[i] - 'a';
            cnt[index] = max(cnt[index], maxLen);
        }
        
        int res = 0;
        for (int c : cnt) res += c;
        return res;
    }
};