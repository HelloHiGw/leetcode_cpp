// class Solution {
// public:
//     int maxLength(vector<string>& arr) {
//         vector<bool> visited(26, false);
//         int res = 0;
//         backtrack(0, arr, visited, 0, res);
//         return res;
//     }
    
//     void backtrack(int start, vector<string>& arr, vector<bool>& visited, int curr, int& res) {
//         res = max(res, curr);
//         for (int i = start; i < arr.size(); ++i) {
//             bool unique = true;
//             for (int j = 0; j < arr[i].size(); ++j) {
//                 if (visited[arr[i][j] - 'a']) {
//                     for (int k = 0; k < j; ++k) visited[arr[i][k] - 'a'] = false;
//                     unique = false;
//                     break;
//                 } else {
//                     visited[arr[i][j] - 'a'] = true;
//                 }
//             }
//             if (!unique) continue;
//             backtrack(i + 1, arr, visited, curr + arr[i].size(),res);
//             for (char ch : arr[i]) {
//                 visited[ch - 'a']  = false;
//             }
//         }
//     }
// };


class Solution {
public:
    int maxLength(vector<string>& arr) {
        int res = 0;
        backtrack(0, arr, {}, 0, res);
        return res;
    }
    
    void backtrack(int start, vector<string>& arr, bitset<26> visited, int curr, int& res) {
        res = max(res, curr);
        for (int i = start; i < arr.size(); ++i) {
            bool unique = true;
            bitset<26> bits;
            for (char ch : arr[i]) bits.set(ch - 'a');
            if (bits.count() < arr[i].size()) continue;
            if ((visited & bits).any()) continue;
            // not easy to undo the change unless you keep the copy, so not use &
            backtrack(i + 1, arr, visited | bits, curr + arr[i].size(),res);
        }
    }
};