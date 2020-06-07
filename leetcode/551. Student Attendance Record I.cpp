class Solution {
public:
    bool checkRecord(string s) {
        int cntA = 0, cntL = 0;
        for (int i = 0; i < s.size(); ++ i) {
            if (s[i] == 'A') {
                ++cntA;
            }
            if (s[i] == 'L') {
                ++cntL;
            } else {
                cntL = 0;
            }
            if (cntA == 2 || cntL == 3) return false;
        }
        return true;
    }
};