class Solution {
public:
    int arrangeCoins(int n) {
        if (n <= 1) return n;
        int left = 1, right = n;
        long mid, ans;
        // find the first f(i) > n, then answer is i - 1
        while (left < right) {
            mid = left + (right - left) / 2;
            ans = mid * (mid + 1) / 2;
            if (ans > n) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }
        return left - 1;
    }
};