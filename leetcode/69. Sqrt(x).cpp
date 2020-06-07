class Solution {
public:
    int mySqrt(int x) {
        if (x <= 1) return x;
        int left = 1, right = x;
        // find the first integer that i * i > x, then i - 1 is the answer
        // in essence, binary search the answer
        while (left < right) {
            long mid = left + (right - left) / 2;
            if (mid * mid > x) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }
        return left - 1;
    }
};