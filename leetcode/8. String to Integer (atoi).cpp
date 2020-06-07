class Solution {
public:
    int myAtoi(string str) {
        int i = 0;
        while (i < str.size() && str[i] == ' ') ++i;
        int sign = 1;
        if (i < str.size() && (str[i] == '+' || str[i] == '-')) {
            sign = str[i] == '+' ? 1 : -1;
            ++i;
        }
        int base = 0;
        while (i < str.size() && isdigit(str[i])) {
            int d = str[i++] - '0';
            if (INT_MAX / 10 < base || INT_MAX / 10 == base && INT_MAX % 10 < d) {
                return sign == 1 ? INT_MAX : INT_MIN;
                // INT_MAX = 2147483647 INT_MIN = -2147483648
                // if sign == -1, d = 8, INT_MAX % 10 < d, return INT_MIN = -2147483648 == -(base * 10 + d)
            }
            base = base * 10 + d;
        }
        return sign * base;
    }
};