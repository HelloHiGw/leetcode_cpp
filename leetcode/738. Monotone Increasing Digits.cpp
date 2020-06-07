class Solution {
// public:
//     int monotoneIncreasingDigits(int N) {
//         string s = to_string(N);
//         for (int i = 0; i < s.size() - 1; ++i) {  // s not empty
//             if (s[i] > s[i + 1]) {
//                 while (i && s[i] == s[i - 1]) --i;
//                 --s[i];
//                 for (int j = i + 1; j < s.size(); ++j) s[j] = '9';
//                 break;
//             }
//         }
//         return stoi(s);
//     }
// };


public:
    int monotoneIncreasingDigits(int N) {
        string s = to_string(N);
        int marker = s.size();
        for (int i = s.size() - 1; i > 0; --i) {
            if (s[i] < s[i - 1]) {
                marker = i;
                --s[i - 1];
            }
        }
        for (int i = marker; i < s.size(); ++i) s[i] = '9';
        return stoi(s);
    }
};
