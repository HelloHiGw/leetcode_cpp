class Solution {
public:
    int numUniqueEmails(vector<string>& emails) {
        unordered_set<string> st;
        for (string &s : emails) {
            int i = 0;
            string res;
            while (i < s.size()) {
                if (s[i] == '+' || s[i] == '@') {
                    while (s[i] != '@') ++i;
                    res += s.substr(i);
                    break;
                }
                if (s[i] != '.') res += s[i];
                ++i;
            }
            st.insert(res);
        }
        return st.size();
    }
};