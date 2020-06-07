class Solution {
public:
    string mostCommonWord(string paragraph, vector<string>& banned) {
        unordered_set<string> st;
        for (string s : banned) {
            st.insert(s);
        }
        unordered_map<string, int> m;
        string res;
        int maxCnt = -1;
        int i = 0;
        while (i < paragraph.size()) {
            while (i < paragraph.size() && !isalpha(paragraph[i])) ++i;
            string word;
            while (i < paragraph.size() && isalpha(paragraph[i])) {
                word += tolower(paragraph[i]);
                ++i;
            }
            if (st.find(word) == st.end()) {
                if (++m[word] > maxCnt) {
                    maxCnt = m[word];
                    res = word;
                }
            }
        }
        return res;
    }
};