class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char, int> need, window;
        for (char ch : t) ++need[ch];
        int left = 0, right = 0;
        int valid = 0;
        int minLen = INT_MAX, start = -1;
    
        while (right < s.size()) {
            char c = s[right];
            // [left, right)
            ++right;
            if (need.count(c)) {
                ++window[c];
                // current window contains all the count of c, ++valid
                if (window[c] == need[c]) ++valid;
            }
            // current window contains all the different char and their corresponding count
            // it is a feasible answer
            while (valid == need.size()) {
                // optimal answer
                if (right - left < minLen) {
                    minLen = right - left;
                    start = left;
                }
                
                char d = s[left];
                ++left;
                // mirror of expanding the right
                if (need.count(d)) {
                    if (window[d] == need[d]) --valid;
                    --window[d];
                }
            }
        }
        
        return minLen == INT_MAX ? "" : s.substr(start, minLen);
    }
};