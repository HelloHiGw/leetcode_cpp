class Solution {
public:
    int maximum69Number (int num) {
        string s = to_string(num);
        for (char& ch : s) {
            if (ch == '6') {
                ch = '9';
                break;
            }
        }
        return stoi(s);
    }
};

class Solution {
public:
    int maximum69Number (int num) {
        int firstSix = -1;
        int copy = num;
        for (int i = 0; num > 0; ++i) {
            if (num % 10 == 6) firstSix = i;
            num /= 10;
        }
        if (firstSix == -1) return copy;
        return copy + 3 * pow(10, firstSix);
    }
};