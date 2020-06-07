class Solution {
public:
    int numPrimeArrangements(int n) {
        const int MOD = 1e9 + 7;
        vector<bool> isPrime(110, true);
        int count = 0;
        
        for (int i = 2; i <= n; ++i) {
            if (isPrime[i]) {
                ++count;
                for (int j = 2 * i; j <= n; j += i) isPrime[j] = false;
            }
        }
        
        long res = factorial(1, count);
        res = factorial(res, n - count);
        return res;
        
    }
    
private:
    const int MOD = 1e9 + 7;
    
    long factorial(long res, int n) {
        while (n > 0) {
            res = (res * n) % MOD;
            --n;
        }
        return res;
    }
};