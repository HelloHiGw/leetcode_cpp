class Solution {
public:
    int maxArea(int h, int w, vector<int>& hor, vector<int>& ver) {
        const int MOD = 1e9 + 7;
        sort(hor.begin(), hor.end());
        sort(ver.begin(), ver.end());
        hor.insert(hor.begin(), 0);
        hor.push_back(h);
        ver.insert(ver.begin(), 0);
        ver.push_back(w);
        int len1 = 0, len2 = 0;
        
        for (int i = 1; i < hor.size(); ++i) {
            len1 = max(len1, hor[i] - hor[i - 1]);
        }
        for (int i = 1; i < ver.size(); ++i) {
            len2 = max(len2, ver[i] - ver[i - 1]);
        }
        
        return ((long)len1 * len2) % MOD;
    }
};