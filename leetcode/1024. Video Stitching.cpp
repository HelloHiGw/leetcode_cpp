// switch to jump game
class Solution {
public:
    int videoStitching(vector<vector<int>>& clips, int T) {
        vector<int> ends(T + 1, 0);
        for (auto& clip : clips) {
            if (clip[0] <= T) ends[clip[0]] = max(ends[clip[0]], clip[1]);
        }
        int res = 0;
        for (int i = 0, end = 0, nextEnd = 0; end < T; end = nextEnd, ++res) {
            for (; i <= end; ++i) nextEnd = max(nextEnd, ends[i]);
            if (nextEnd == end) return -1;
        }
        return res;
    }
};

