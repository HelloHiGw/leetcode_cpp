class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int H) {
        int left = 1, right = *max_element(piles.begin(), piles.end());
        while (left < right) {
            int mid = left + (right - left) / 2;
            int hours = timeToEat(piles, mid);
            if (hours <= H) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }
        return left;
    }
    
private:
    int timeToEat(vector<int>& piles, int K) {
        int hours = 0;
        for (int p : piles) {
            // ceil(1.0 * p / K)
            hours += (p + K - 1) / K;
        }
        return hours;
    }
};