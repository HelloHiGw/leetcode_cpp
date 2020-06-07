/*
you can not use int p or unsigned int p
if (n < 0) {
    p = -n;  // -n for INT_MIN will overflow (you still use int before asign)
}
*/
class Solution {
public:
    double myPow(double x, int n) {
        double res = 1;
        long p = n;
        if (p < 0) {
            p = -p;
            x = 1 / x;
        } 

        while (p) {
            if (p & 1) res *= x;
            x *= x;
            p >>= 1;
        }
        
        return res;
    }
};