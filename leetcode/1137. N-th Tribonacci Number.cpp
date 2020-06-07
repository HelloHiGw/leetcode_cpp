class Solution {
public:
    int tribonacci(int n) {
        if (n <= 1) return n;
        if (n == 2) return 1;
        int T0 = 0, T1 = 1, T2 = 1;
        for (int i = 3; i <= n; ++i) {
            int curr = T0 + T1 + T2;
            T0 = T1;
            T1 = T2;
            T2 = curr;
        }
        return T2;
    }
};