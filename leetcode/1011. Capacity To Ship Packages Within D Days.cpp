class Solution {
public:
    int shipWithinDays(vector<int>& weights, int D) {
        int left = *max_element(weights.begin(), weights.end()), right = accumulate(weights.begin(), weights.end(), 0);
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (isValid(mid, weights, D)) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }
        return left;
    }
    
private:
    bool isValid(int cap, vector<int>& weights, int D) {
        int days = 0;
        int curr = 0;
        for (int w : weights) {
            if (curr + w > cap) {
                ++days;
                curr = 0;
            }
            curr += w;
        }
        ++days;
        return days <= D;
    }
};