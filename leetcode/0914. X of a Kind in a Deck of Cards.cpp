class Solution {
public:
    bool hasGroupsSizeX(vector<int>& deck) {
        unordered_map<int, int> m;
        for (int num : deck) {
            m[num] += 1;
        }
        int res = 0;
        for (auto it : m) {
            res = getGcd(res, it.second);
        }
        return res >= 2;
    }
    
    int getGcd(int a, int b) {
        if (b == 0) return a;
        return getGcd(b, a % b);
    }
};