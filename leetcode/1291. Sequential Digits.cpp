// class Solution {
// public:
//     vector<int> sequentialDigits(int low, int high) {
//         vector<int> res;
//         for (int i = 1; i < 10; ++i) {
//             backtrack(low, high, 0, i, res);
//         }
//         sort(res.begin(), res.end());
//         return res;
//     }
    
// private:
//     // just simple dfs, not backtrack, because you can only choose d + 1 at current level, no other choice
//     void backtrack(int low, int high, int curr, int d, vector<int>& res) {
//         if (curr >= low && curr <= high) {
//             res.push_back(curr);
//         }
//         if (curr > high || d > 9) return;
//         curr = curr * 10 + d;
//         backtrack(low, high, curr, d + 1, res);
//     }
    
// };

class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
        vector<int> res;
        for (int i = 1; i < 10; ++i) {
            int n = 0, d = i;
            while (true) {
                n = n * 10 + d;
                ++d;
                if (n >= low && n <= high) res.push_back(n);
                if (n > high || d == 10) break;
            }
        }
        sort(res.begin(), res.end());
        return res;
    }
};
