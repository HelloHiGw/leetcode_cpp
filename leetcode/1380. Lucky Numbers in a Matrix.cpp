// class Solution {
// public:
//     vector<int> luckyNumbers (vector<vector<int>>& matrix) {
//         vector<int> res;
//         for (int i = 0; i < matrix.size(); ++i) {
//             int c = 0;
//             for (int j = 1; j < matrix[i].size(); ++j) {
//                 if (matrix[i][j] < matrix[i][c]) c = j;
//             }
//             int k = 0;
//             for (k = 0; k < matrix.size(); ++k) {
//                 if (matrix[k][c] > matrix[i][c]) break;
//             }
//             if (k == matrix.size()) res.push_back(matrix[i][c]);
//         }
//         return res;
//     }
// };

class Solution {
public:
    vector<int> luckyNumbers (vector<vector<int>>& matrix) {
        int r = -1, c = -1;
        for (int i = 0; i < matrix.size(); ++i) {
            int j = 0;
            for (int k = 1; k < matrix[i].size(); ++k) {
                if (matrix[i][k] < matrix[i][j]) j = k;
            }
            if (r == -1 || matrix[r][c] < matrix[i][j]) {
                r = i;
                c = j;
            }
        }
        for (int i = 0; i < matrix.size(); ++i) {
            if (matrix[i][c] > matrix[r][c]) return {};
        }
        return vector<int>{matrix[r][c]};
    }
};

/* 
there is at most 1 lucky number
a b c
d e f
i j k
let i be the lucky number, will b be another one ? no
a < i < j, if b is a lucky number, b < a and b > j, which is impossible (a < j)
the same for c , e, and f ...

a b c
d e f
if the min of two row is a and f, if a < f, a will not be a lucky number:
a < f < d, which not satisfy a > d for lucky number a
*/