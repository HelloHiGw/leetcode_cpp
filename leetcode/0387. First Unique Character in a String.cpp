// class Solution {
// public:
//     int firstUniqChar(string s) {
//         vector<int> cnt(26);
//         for (char ch : s) {
//             ++cnt[ch - 'a'];
//         }
//         for (int i = 0; i < s.size(); ++i) {
//             if (cnt[s[i] - 'a'] == 1) return i; 
//         }
//         return -1;
//     }
// };


class Solution {
public:
    int firstUniqChar(string s) {
        if (s.empty()) return -1;
        unordered_map<char, int> m;
        int slow = 0, fast = 0;
        while (fast < s.size()) {
            ++m[s[fast]];
            while (slow < s.size() && m[s[slow]] > 1) ++slow;
            if (slow == s.size()) return -1;
            ++fast;
        }
        return slow;
    }
};