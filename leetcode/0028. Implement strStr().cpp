// class Solution {
// public:
//     int strStr(string haystack, string needle) {
//         if (needle.empty()) return 0;
//         if (haystack.size() < needle.size()) return -1;
//         for (int i = 0; i <= haystack.size() - needle.size(); ++i) {
//             int j = -1;
//             for (j = 0; j < needle.size() && haystack[i + j] == needle[j]; ++j);
//             if (j == needle.size()) return i;
//         }
//         return -1;
//     }
// };

class Solution {
public:
    int strStr(string haystack, string needle) {
        if (needle.empty()) return 0;
        vector<int> next = getNext(needle);
        int i = 0, j = 0;
        int pSize = needle.size();
        while (i < haystack.size() && j < pSize) {
            if (j == -1 || haystack[i] == needle[j]) {
                ++i;
                ++j;
            } else {
                j = next[j];
            }
        }
        if (j == needle.size()) return i - j;
        return -1;
    }
    
    vector<int> getNext(string p) {
        vector<int> next(p.size());
        next[0] = -1;
        int i = 0, j = -1;
        while (i < p.size() - 1) {
            if (j == -1 || p[i] == p[j]) {
                ++i;
                ++j;
                next[i] = j;
            } else {
                j = next[j];
            }
        }
        return next;
    }
};