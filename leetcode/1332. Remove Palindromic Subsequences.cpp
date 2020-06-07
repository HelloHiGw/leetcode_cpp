class Solution {
public:
    int removePalindromeSub(string s) {
        if (s.empty()) return 0;
        if (isPalindrome(s)) return 1;
        return 2;
    }
    
    bool isPalindrome(string s) {
        int i = 0, j = s.size() - 1;
        while (i < j) {
            if (s[i] != s[j]) return false;
            ++i;
            --j;
        }
        return true;
    }
};