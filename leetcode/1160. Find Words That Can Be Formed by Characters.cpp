class Solution {
public:
    int countCharacters(vector<string>& words, string chars) {
        unordered_map<char, int> m;
        for (char ch : chars) {
            ++m[ch];
        }
        int res = 0;
        for (string s : words) {
            unordered_map<char, int> freq;
            bool flag = true;
            for (char ch : s) {
                if (++freq[ch] > m[ch]) {
                    flag = false;
                    break;
                }
            }
            res += flag ? s.size() : 0;
        }
        return res;
    }
};