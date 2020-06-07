// class Solution {
// public:
//     bool backspaceCompare(string S, string T) {
//         return recover(S) == recover(T);
//     }
    
//     string recover(string s) {
//         string str;
//         for (char ch : s) {
//             if (ch == '#') {
//                 if (str.size() > 0) str.pop_back();
//             } else {
//                 str += ch;
//             }
//         }
//         return str;
//     }
// };


class Solution {
public:
    bool backspaceCompare(string S, string T) {
        int i = (int)S.size() - 1, j = (int)T.size() - 1, cnt = 0;
        while (i >= 0 || j >= 0) {
            for (cnt = 0; i >= 0 && (cnt || S[i] == '#'); --i) {
                S[i] == '#' ? ++cnt : --cnt;
            }
            for (cnt = 0; j >= 0 && (cnt || T[j] == '#'); --j) {
                T[j] == '#' ? ++cnt : --cnt;
            }
            if (i >= 0 && j >= 0 && S[i] == T[j]) {
                --i;
                --j;
            } else {
                break;
            }
        }
        return i < 0 && j < 0;
    }
};


