/*
n = heaters.size() m = houses.size()
O(nlogn + mlogn)
*/
class Solution {
public:
    int findRadius(vector<int>& houses, vector<int>& heaters) {
        int n = heaters.size();
        int res = 0;
        sort(heaters.begin(), heaters.end());
        
        for (int house : houses) {
            // find the first equal or right position heater
            int left = 0, right = n, mid;
            while (left < right) {
                mid = left + (right - left) / 2;
                if (heaters[mid] >= house) {
                    right = mid;
                } else {
                    left = mid + 1;
                }
            }
            
            int dist1 = left < n ? heaters[left] - house : INT_MAX;
            int dist2 = left ? house - heaters[left - 1]: INT_MAX;
            // for current house, min(dist1, dist2) is enough
            res = max(res, min(dist1, dist2));
        }
        
        return res;
    }
};s