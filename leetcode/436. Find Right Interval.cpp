class Solution {
public:
    vector<int> findRightInterval(vector<vector<int>>& intervals) {
        int n = intervals.size();
        // start to index
        unordered_map<int, int> mp;
        for (int i = 0; i < n; ++i) {
            mp[intervals[i][0]] = i; 
        }
        sort(intervals.begin(), intervals.end());
        
        vector<int> res(n);
        for (int i = 0; i < n; ++i) {
            int ub = upperBound(intervals, i + 1, n, intervals[i]);
            if (ub == n) {
                res[mp[intervals[i][0]]] = -1;
            } else {
                res[mp[intervals[i][0]]] = mp[intervals[ub][0]];
            }
        }
        return res;
    }
    
private:
    int upperBound(vector<vector<int>>& intervals, int left, int right, vector<int>& v) {
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (intervals[mid][0] >= v[1]) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }
        return left;
    }
};