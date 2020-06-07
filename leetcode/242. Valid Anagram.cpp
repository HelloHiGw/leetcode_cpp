// class Solution {
// public:
//     bool isAnagram(string s, string t) {
//         if (s.size() != t.size()) return false;
//         unordered_map<char, int> mp;
//         for (char ch : s) ++mp[ch];
//         for (char ch : t) {
//             if (!mp.count(ch) || mp[ch] == 0) return false;
//             --mp[ch];
//         }
//         return true;
//     }
// };

class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.size() != t.size()) return false;
        unordered_map<char, int> mp;
        for (char ch : s) ++mp[ch];
        for (char ch : t) --mp[ch];
        for (auto& it : mp) {
            if (it.second != 0) return false;
        }
        return true;
    }
};