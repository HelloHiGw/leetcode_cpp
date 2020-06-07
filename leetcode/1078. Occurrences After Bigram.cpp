// class Solution {
// public:
//     vector<string> findOcurrences(string text, string first, string second) {
//         vector<string> words;
//         for (int i = 0, j = 0; i < text.size(); i = j + 1) {
//             for (j = i; j < text.size() && text[j] != ' '; ++j);
//             words.push_back(text.substr(i, j - i));
//         }
        
//         vector<string> res;
//         for (int i = 2; i < words.size(); ++i) {
//             if (words[i - 2] == first && words[i - 1] == second) {
//                 res.push_back(words[i]);
//             }
//         }
        
//         return res;
//     }
// };


class Solution {
public:
    vector<string> findOcurrences(string text, string first, string second) {
        istringstream in(text);
        string prev2, prev, word;
        vector<string> res;
        
        while (in >> word) {
            if (prev2 == first && prev == second) res.push_back(word);
            prev2 = prev;
            prev = word;
        }
        
        return res;
    }
};