class Solution {
public:
    int minTaps(int n, vector<int>& ranges) {
        vector<int> ends(n + 1, 0);
        for (int i = 0; i < ranges.size(); ++i) {
            int start = max(0, i - ranges[i]);  // if smaller than 0, we choose 0, crucial here
            ends[start] = max(ends[i], i + ranges[i]);
        }
        int res = 0;
        int end = 0, nextEnd = 0;
        for (int i = 0; i < n ; ++i) {
            nextEnd = max(nextEnd, ends[i]);
            if (i == end) {  // go to the next level
                end = nextEnd;
                ++res;
                if (end == n) break;  // early stop
            } else if (i > end) {  // can not reach
                return -1;
            }
        }
        return res;
    }
};