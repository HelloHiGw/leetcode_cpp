// class Solution {
// public:
//     char findTheDifference(string s, string t) {
//         vector<int> count(26);
//         for (int i = 0; i < s.size(); ++i) {
//             ++count[t[i] - 'a'];
//             --count[s[i] - 'a'];
//         }
//         ++count[t.back() - 'a'];
//         for (int i = 0; i < 26; ++i) {
//             if (count[i]) return i + 'a';
//         }
//         return ' ';
//     }
// };

// class Solution {
// public:
//     char findTheDifference(string s, string t) {
//         char res = 0;
//         for (char ch : s) res ^= ch;
//         for (char ch : t) res ^= ch;
//         return res;
//     }
// };

class Solution {
public:
    char findTheDifference(string s, string t) {
        char res = t.back();
        for (int i = 0; i < s.size(); ++i) {
            res ^= s[i] ^ t[i];
        }
        return res;
    }
};