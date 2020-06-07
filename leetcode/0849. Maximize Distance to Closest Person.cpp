class Solution {
public:
    int maxDistToClosest(vector<int>& seats) {
        int count = 0, res = -1;
        int i = 0;
        while (seats[i] == 0) ++i;
        res = max(res, i);
        for (; i < seats.size(); ++i) {
            if (seats[i] == 1) {
                res = max(res, (count + 1) / 2);
                count = 0;
            } else {
                ++count;
            }
        }
        if (seats.back() == 0) res = max(res, count);
        return res;
    }
};