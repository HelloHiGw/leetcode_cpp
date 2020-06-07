// class Solution {
// public:
//     vector<string> letterCombinations(string digits) {
//         if (digits.empty()) return {};
//         vector<string> letters {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
//         vector<string> res;
//         myLetterCombinations("", digits, 0, letters, res);
//         return res;
//     }
    
//     void myLetterCombinations(string prefix, string digits, int offset, vector<string> letters, vector<string> &res) {
//         if (offset == digits.size()) {
//             res.push_back(prefix);
//             return;
//         }
//         string letter = letters[digits[offset] - '0'];
//         for (int i = 0; i < letter.size(); ++i) {
//             myLetterCombinations(prefix + letter[i], digits, offset + 1, letters, res);
//         }
//     }
// };


// same thought as queue of java in most voted answer
class Solution {
public:
    vector<string> letterCombinations(string digits) {
        if (digits.empty()) return {};
        vector<string> letters {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        vector<string> res{""};
        for (int i = 0; i < digits.size(); ++i) {
            string letter = letters[digits[i] - '0'];
            vector<string> temp;
            for (int j = 0; j < letter.size(); ++j) {
                for (string s : res) temp.push_back(s + letter[j]);
            }
            res = temp;
        }
        return res;
    }
};