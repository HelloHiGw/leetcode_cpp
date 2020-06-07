// Time complexity:  O(n^2)
// Space complexity: O(n^2)
// class Solution {
// public:
//     int fourSumCount(vector<int>& A, vector<int>& B, vector<int>& C, vector<int>& D) {
//         unordered_map<int, int> m;
//         for (int a : A) {
//             for (int b : B) {
//                 ++m[a + b];
//             }
//         }
//         int res = 0;
//         for (int c : C) {
//             for (int d : D) {
//                 res += m[-c - d];
//             }
//         }
//         return res;
//     }
// };


class Solution {
public:
    int fourSumCount(vector<int>& A, vector<int>& B, vector<int>& C, vector<int>& D) {
        unordered_map<int, int> m1, m2;
        int n = A.size();
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                ++m1[A[i] + B[j]];
                ++m2[C[i] + D[j]];
            }
        }
        int res = 0;
        for (auto it : m1) {
            res += m2[-it.first] * it.second;
        }
        return res;
    }
};