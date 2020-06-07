class Solution {
public:
    int findLongestChain(vector<vector<int>>& pairs) {
        if (pairs.empty()) return 0;
        sort(pairs.begin(), pairs.end(), [&](vector<int>& v1, vector<int>& v2){
            if (v1[1] != v2[1]) return v1[1] < v2[1];
            return v1[0] > v2[0];
        });
        
        int last = pairs[0][1];
        int res = 1;
        for (int i = 1; i < pairs.size(); ++i) {
            if (pairs[i][0] > last) {
                ++res;
                last = pairs[i][1];
            }
        }
        
        return res;
    }
};

