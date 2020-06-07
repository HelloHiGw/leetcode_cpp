class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        unordered_map<char, int> need, window;
        for (char ch : p) ++need[ch];
        
        int left = 0, right = 0;
        int valid = 0;
        vector<int> res;
        
        while (right < s.size()) {
            char c = s[right];
            ++right;
            if (need.count(c)) {
                ++window[c];
                if (window[c] == need[c]) ++valid;
            }
            
            while (valid == need.size()) {
                if (right - left == p.size()) {
                    res.push_back(left);
                }
                
                char d = s[left];
                ++left;
                if (need.count(d)) {
                    if (window[d] == need[d]) --valid;
                    --window[d];
                }
            }
        }
        
        return res;
    }
};