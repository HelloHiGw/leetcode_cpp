class Solution {
public:
    bool judgeCircle(string moves) {
        int L = 0, R = 0, U = 0, D = 0;
        for (char ch : moves) {
            if (ch == 'L') {
                ++L;
            } else if (ch == 'R') {
                ++R;
            } else if (ch == 'U') {
                ++U;
            } else {
                ++D;
            }
        }
        return L == R && U == D;
    }
};