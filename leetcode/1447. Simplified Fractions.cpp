class Solution {
public:
    vector<string> simplifiedFractions(int n) {
        vector<string> res;
        for (int down = 2; down <= n; ++down) {
            for (int up = 1; up < down; ++up) {
                if (getGcd(up, down) == 1) {
                    res.push_back(to_string(up) + "/" + to_string(down));
                }
            }
        }
        return res;
    }
    
private:
    int getGcd(int a, int b) {
        if (b == 0) return a;
        return getGcd(b, a % b);
    }
};