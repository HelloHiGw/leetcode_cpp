class Solution {
public:
    bool detectCapitalUse(string word) {
        if (word.size() <= 1) return true;
        bool upper = false, lower = false;
        for (int i = 1; i < word.size(); ++i) {
            if (isupper(word[i])) {
                upper = true;
            } else {
                lower = true;
            }
        }
        if (upper && lower) return false;
        if (upper && islower(word[0])) return false;
        return true;
    }
};