class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        unordered_map<char, int> need, window;
        for (char ch : s1) ++need[ch];
        
        int left = 0, right = 0;
        int valid = 0;
        
        while (right < s2.size()) {
            char c = s2[right];
            ++right;
            if (need.count(c)) {
                ++window[c];
                if (window[c] == need[c]) ++valid;
            }
            
            while (valid == need.size()) {
                if (right - left == s1.size()) return true;
                char d = s2[left];
                ++left;
                if (need.count(d)) {
                    if (window[d] == need[d]) --valid;
                    --window[d];
                }
            }
        }
        
        return false;
    }
};


class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        unordered_map<char, int> need, window;
        for (char ch : s1) ++need[ch];
        
        int left = 0, right = 0;
        int valid = 0;
        
        while (right < s2.size()) {
            char c = s2[right];
            ++right;
            if (need.count(c)) {
                ++window[c];
                if (window[c] == need[c]) ++valid;
            }
            
           // printf("window is [%d %d),  valid is %d\n", left, right, valid);
            
            while (right - left >= s1.size()) {  // seems almost the same as above
                if (valid == need.size()) return true;
                char d = s2[left];
                ++left;
                if (need.count(d)) {
                    if (window[d] == need[d]) --valid;
                    --window[d];
                }
            }
        }
        
        return false;
    }
};