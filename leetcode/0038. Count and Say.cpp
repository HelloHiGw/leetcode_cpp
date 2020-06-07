class Solution {
public:
    string countAndSay(int n) {
        string res = "1";
        for (int i = 1; i < n; ++i) {
            string temp;
            for (int j = 0, k = 0; j < res.size(); j = k) {
                while (k < res.size() && res[k] == res[j]) ++k;
                temp += to_string(k - j) + res[j];
            }
            res = temp;
        }
        return res;
    }
};