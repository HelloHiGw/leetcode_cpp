class Solution {
public:
    string reformat(string s) {
        vector<char> nums;
        vector<char> alphas;
        for (char ch : s) {
            ch >= '0' && ch <= '9' ? nums.push_back(ch) : alphas.push_back(ch);
        }
        
        int n1 = nums.size(), n2 = alphas.size();
        if (abs(n1 - n2) > 1) return "";
        
        string res;
        int minLen = min(n1, n2);
        for (int i = 0; i < minLen; ++i) {
            res += nums[i];
            res += alphas[i];
        }
        
        if (n1 > n2) res += nums.back();
        if (n2 > n1) res = alphas.back() + res;
        
        return res;
    }
};

