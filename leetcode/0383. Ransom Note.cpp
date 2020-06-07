class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        unordered_map<char, int> m;
        for (char ch : magazine) {
            ++m[ch];
        }
        for (int i = 0; i < ransomNote.size(); ++ i) {
            char ch = ransomNote[i];
            if (m[ch]-- == 0) return false;
        }
        return true;
    }
};