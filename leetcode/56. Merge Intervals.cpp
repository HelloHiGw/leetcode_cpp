class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        if (intervals.empty()) return {};
        sort(intervals.begin(), intervals.end(), [](vector<int>& v1, vector<int>&v2){
            if (v1[0] != v2[0]) return v1[0] < v2[0];
            return v1[1] < v2[1];
        });
        
        vector<vector<int>> res;
        res.push_back(intervals[0]);
        for (int i = 1; i < intervals.size(); ++i) {
            if (intervals[i][0] > res.back()[1]) {
                res.push_back(intervals[i]);
            } else if (intervals[i][1] > res.back()[1]){
                res.back()[1] = intervals[i][1];
            }
        }
        
        return res;
    }
};