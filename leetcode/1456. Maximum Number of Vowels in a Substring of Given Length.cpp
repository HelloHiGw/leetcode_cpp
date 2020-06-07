class Solution {
public:
    int maxVowels(string s, int k) {
        int left = 0, right = 0;
        int valid = 0;
        int res = 0;
        
        while (right < s.size()) {
            char c = s[right];
            ++right;
            if (isVowel(c)) ++valid;
            
            // changing to if also work, the window size is k
            while (right - left > k) {
                char d = s[left];
                ++left;
                if (isVowel(d)) --valid;
            }
            
            res = max(res, valid);
        }
        
        return res;
    }
    
private:
    bool isVowel(char ch) {
        return ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u';
    }
};


class Solution {
public:
    int maxVowels(string s, int k) {
        int valid = 0;
        for (int i = 0; i < k; ++i) {
            if (isVowel(s[i])) ++valid;
        }
        
        int res = valid;
        for (int i = k; i < s.size(); ++i) {
            if (isVowel(s[i - k])) --valid;
            if (isVowel(s[i])) ++valid;
            res = max(res, valid);
        }
        
        return res;
    }
    
private:
    bool isVowel(char ch) {
        return ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u';
    }
};


class Solution {
public:
    int maxVowels(string s, int k) {
        int res = 0;
        int valid = 0;
        
        for (int i = 0; i < s.size(); ++i) {
            valid += isVowel(s[i]);
            if (i >= k) valid -= isVowel(s[i - k]);
            res = max(res, valid);
        }
        
        return res;
    }
    
private:
    bool isVowel(char ch) {
        return ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u';
    }
};