class Solution {
public:
    int repeatedStringMatch(string A, string B) {
        string res;
        int cnt = 0;
        while (res.size() < B.size()) {
            res += A;
            ++cnt;
        }
        if (res.find(B) != string::npos) return cnt;
        res += A;
        ++cnt;
        if (res.find(B) != string::npos) return cnt;
        return -1;
    }
};