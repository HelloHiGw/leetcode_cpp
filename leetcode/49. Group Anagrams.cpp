// class Solution {
// public:
//     vector<vector<string>> groupAnagrams(vector<string>& strs) {
//         unordered_map<string, vector<string>> m;
//         for (string s : strs) {
//             string t = s;
//             sort(t.begin(), t.end());
//             m[t].push_back(s);
//         }
//         vector<vector<string>> res;
//         for (auto it : m) {
//             res.push_back(it.second);
//         }
//         return res;
//     }
// };


class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> m;
        for (string s : strs) {
            vector<int> cnt(26);  // counting sort, O(L) instead of O(LlogL)
            for (char ch : s) ++cnt[ch - 'a'];
            string t;
            for (int i = 0; i< 26; ++i) {
                if (cnt[i] == 0) continue;
                t += string(cnt[i], i + 'a');
            }
            m[t].push_back(s);
        }
        vector<vector<string>> res;
        for (auto it : m) {
            res.push_back(it.second);
        }
        return res;
    }
};