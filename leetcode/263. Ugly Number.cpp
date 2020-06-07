class Solution {
public:
    bool isUgly(int num) {
        if (num <= 0) return false;
        vector<int> primes = {2, 3, 5};
        for (int i = 0; i < primes.size() && num != 1; ++i) {
            while (num % primes[i] == 0) num /= primes[i];
        }
        return num == 1;
    }
};