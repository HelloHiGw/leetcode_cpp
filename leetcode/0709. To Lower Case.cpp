class Solution {
public:
    string toLowerCase(string str) {
        for (char &ch : str) {
            if ('A' <= ch && ch <= 'Z') ch += 32;
        }
        return str;
    }
};