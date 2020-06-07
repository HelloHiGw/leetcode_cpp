class Solution {
public:
    vector<int> getNoZeroIntegers(int n) {
        for (int i = 1; i <= n / 2; ++i) {
            if (isValid(i) && isValid(n - i)) return {i, n - i};
        }
        return {-1, -1};
    }
    
private:
    bool isValid(int n) {
        while (n) {
            if (n % 10 == 0) return false;
            n /= 10;
        }
        return true;
    }
};