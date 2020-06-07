class Solution {
public:
    vector<bool> prefixesDivBy5(vector<int>& A) {
        vector<bool> res;
        int num = 0;
        for (int a : A) {
            num = (num * 2 + a) % 5;
            res.push_back(num == 0);
        }
        return res;
    }
};