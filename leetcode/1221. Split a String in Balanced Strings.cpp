class Solution {
public:
    int balancedStringSplit(string s) {
        int cntL = 0, cntR = 0;
        int res = 0;
        for (char ch : s) {
            ch == 'L' ? ++cntL : ++cntR;
            if (cntL == cntR) {
                ++res;
                cntL = cntR = 0;
            }
        }
        return res;
    }
};