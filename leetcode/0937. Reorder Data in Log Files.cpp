// class Solution {
// public:
//     vector<string> reorderLogFiles(vector<string>& logs) {
//         vector<string> letter, digit;
//         for (string s : logs) {
//             int i = 0;
//             while (s[i] != ' ') ++i;
//             if (isdigit(s[i + 1])) {
//                 digit.push_back(s);
//             } else {
//                 string temp = s.substr(i) + " " + s.substr(0, i);
//                 letter.push_back(temp);
//             }
//         }
//         sort(letter.begin(), letter.end());
//         for (string &s : letter) {
//             int i = s.size() - 1;
//             while (s[i] != ' ') --i;
//             s = s.substr(i + 1) + s.substr(0, i); 
//         }
//         letter.insert(letter.end(), digit.begin(), digit.end());
//         return letter;
//     }
// };


class Solution {
public:
    vector<string> reorderLogFiles(vector<string>& logs) {
        vector<string> digit;
        vector<pair<string, string>> letter;
        for (string s : logs) {
            int i = 0;
            while (s[i] != ' ') ++i;
            if (isdigit(s[i + 1])) {
                digit.push_back(s);
            } else {
                letter.push_back({s.substr(0, i), s.substr(i)});
            }
        }
        sort(letter.begin(), letter.end(), cmp);
        vector<string> ans;
        for (auto it : letter) {
            ans.push_back(it.first + it.second);
        }
        ans.insert(ans.end(), digit.begin(), digit.end());
        return ans;
    }

    bool static cmp(pair<string, string> a, pair<string, string> b) {
        if (a.second != b.second) return a.second < b.second;
        return a.first < b.first;
    }
};