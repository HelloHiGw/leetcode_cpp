// class Solution {
// public:
//     string reverseOnlyLetters(string S) {
//         int i = 0, j = S.size() - 1;
//         while (i < j) {
//             while (i < j && !isalpha(S[i])) ++i;
//             while (i < j && !isalpha(S[j])) --j;
//             swap(S[i], S[j]);
//             ++i;
//             --j;
//         }
//         return S;
//     }
// };


class Solution {
public:
    string reverseOnlyLetters(string S) {
        for (int i = 0, j = S.size() - 1; i < j;) {
            if (!isalpha(S[i])) {
                ++i;
            } else if (!isalpha(S[j])) {
                --j;
            } else {
                swap(S[i++], S[j--]);
            }
        }
        return S;
    }
};