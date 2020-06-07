// class Solution {
// public:
//     bool buddyStrings(string A, string B) {
//         if (A.size() != B.size()) return false;
//         vector<char> v1;
//         int cnt = 0;
//         vector<int> v(26);
//         bool same = false;
//         for (int i = 0; i < A.size(); ++i) {
//             if (A[i] != B[i]) {
//                 if (cnt == 0) {
//                     v1.push_back(A[i]);
//                     v1.push_back(B[i]);
//                     ++cnt;
//                 } else if (cnt == 1) {
//                     vector<char> v2{B[i], A[i]};
//                     if (v1 != v2) return false;
//                     ++cnt;
//                 } else {
//                     return false;
//                 }
//             } else {
//                 if (++v[A[i] - 'a'] == 2) same = true;
//             }
//         }
//         return cnt > 0 ? true : same;
//     }
// };


class Solution {
public:
    bool buddyStrings(string A, string B) {
        if (A.size() != B.size()) return false;
        if (A == B) return unordered_set<char>(A.begin(), A.end()).size() < A.size();
        vector<int> diff;
        for (int i = 0; i < A.size(); ++i) {
            if (A[i] != B[i]) diff.push_back(i);
            if (diff.size() > 2) return false;
        }
        return diff.size() == 2 && A[diff[0]] == B[diff[1]] && A[diff[1]] == B[diff[0]];
    }
};