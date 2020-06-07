class Solution {
public:
    string intToRoman(int num) {
        vector<string> sym = {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};
        vector<int> val = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
        string res;
        int i = 0;
        while (num) {
            while (num >= val[i]) {
                num -= val[i];
                res += sym[i];
            }
            ++i;
        }
        return res;
    }
};