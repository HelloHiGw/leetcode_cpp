class Solution {
public:
    vector<int> partitionLabels(string S) {
        unordered_map<char, int> last;
        for (int i = 0; i < S.size(); ++i) {
            last[S[i]] = i;
        }
        int start = 0, end = 0;
        vector<int> res;
        for (int i = 0; i < S.size(); ++i) {
            end = max(end, last[S[i]]);
            if (end == i) {
                res.push_back(end - start + 1);
                start = i + 1;
            }
        }
        return res;
    }
};