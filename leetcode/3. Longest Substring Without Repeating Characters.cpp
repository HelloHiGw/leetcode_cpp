// /*
// 如果当前遍历到的字符从未出现过，那么直接扩大右边界，如果之前出现过，那么就分两种情况，
// 在或不在滑动窗口内，如果不在滑动窗口内，那么就没事，当前字符可以加进来，
// 如果在的话，就需要先在滑动窗口内去掉这个已经出现过的字符了
// */

// class Solution {
// public:
//     int lengthOfLongestSubstring(string s) {
//         int res = 0;
//         unordered_map<char, int> m;
//         for (int i = 0, j = 0; i < s.size(); ++i) {
//             if (m.find(s[i]) != m.end()) j = max(j, m[s[i]] + 1);
//             res = max(res, i - j + 1);
//             m[s[i]] = i;
//         }
//         return res;
//     }
// };


/*
much understandable than above
*/
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> window;
        int left = 0, right = 0;
        int res = 0;
        
        while (right < s.size()) {
            char c = s[right];
            ++right;
            ++window[c];
            
            // unfeasible answer
            while (window[c] > 1) {
                char d = s[left];
                ++left;
                --window[d];
            }
            // feasible answer
            res = max(res, right - left);
        }
        
        return res;
    }
};
