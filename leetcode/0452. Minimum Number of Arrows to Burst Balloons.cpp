class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& intervals) {
        if (intervals.empty()) return 0;
        sort(intervals.begin(), intervals.end(), [](vector<int>& v1, vector<int>& v2){
            if (v1[1] != v2[1]) return v1[1] < v2[1];
            return v1[0] > v2[0];
        });
        
        int lastR = intervals[0][1], count = 1;
        for (int i = 1; i < intervals.size(); ++i) {
            if (intervals[i][0] > lastR) {  
                ++count;
                lastR = intervals[i][1];
            }
        }
        return count;
    }
};