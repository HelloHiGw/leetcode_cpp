// class Solution {
// public:
//     bool isLongPressedName(string name, string typed) {
//         if (typed.size() < name.size()) return false;
//         for (int i = 0, j = 0, k = 0, m = 0; i < name.size(); i = j, k = m) {
//             for (j = i; j < name.size() && name[j] == name[i]; ++j);
//             if (typed[k] != name[i]) return false;
//             for (m = k; m < typed.size() && typed[m] == typed[k]; ++m);
//             if (m - k < j - i) return false;
//         }
//         return true;
//     }
// };


class Solution {
public:
    bool isLongPressedName(string name, string typed) {
        int i = 0;
        for (int j = 0; j < typed.size(); ++j) {
            if (i < name.size() && name[i] == typed[j]) {
                ++i;
            } else if (!j || typed[j] != typed[j - 1]) {
                return false;
            }
        }
        return i == name.size();
    }
};