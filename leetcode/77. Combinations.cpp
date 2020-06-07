// class Solution {
// public:
//     vector<vector<int>> combine(int n, int k) {
//         vector<vector<int>> res;
//         backtrack(n, k, 1, {}, res);
//         return res;
//     }
    
//     void backtrack(int n, int k, int start, vector<int> curr, vector<vector<int>>& res) {
//         if (k == 0) {
//             res.push_back(curr);
//             return;
//         }
//         // constraint function
//         // n = 10, k = 5
//         // if start = 7, n must at least be 11, it is possible to generate k numbers
//         if (start + k - 1 > n) {
//             return;
//         }
//         for (int i = start; i <= n; ++i) {
//             curr.push_back(i);
//             backtrack(n, k - 1, i + 1, curr, res);
//             curr.pop_back();  // must pop, because curr is reused in for loop
//         }
//     }
// };

// https://www.cnblogs.com/grandyang/p/4332522.html
class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        if (k > n) return {};
        if (k == 0) return {{}};  // C1 3 = C0 2 + C1 2, C0 2 need to push 3, so vector must not be nullptr, it is an empty vector
        vector<vector<int>> v1 = combine(n - 1, k - 1);
        for (auto& v : v1) v.push_back(n);
        vector<vector<int>> v2 = combine(n - 1, k);
        v1.insert(v1.end(), v2.begin(), v2.end());
        return v1;
    }
};