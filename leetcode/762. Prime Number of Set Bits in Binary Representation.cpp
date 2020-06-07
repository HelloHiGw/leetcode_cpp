// class Solution {
// public:
//     int countPrimeSetBits(int L, int R) {
//         unordered_set<int> primes = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31};
//         int res = 0;
//         for (int i = L; i <= R; ++i) {
//             bitset<32> bits(i);
//             if (primes.count(bits.count())) ++res;
//         }
//         return res;
//     }
// };

// class Solution {
// public:
//     int countPrimeSetBits(int L, int R) {
//         unordered_set<int> primes = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31};
//         int res = 0;
//         for (int i = L; i <= R; ++i) {
//             int cnt = 0;
//             for (int j = i; j > 0; j >>= 1) {
//                 cnt += j & 1;
//             }
//             if (primes.count(cnt)) ++res;
//         }
//         return res;
//     }
// };


class Solution {
public:
    int countPrimeSetBits(int L, int R) {
        int primes = 0b10100000100010100010100010101100;
        int res = 0;
        for (int i = L; i <= R; ++i) {
            bitset<32> bits(i);
            int cnt = bits.count();
            if (primes & (1 << cnt)) ++res;
        }
        return res;
    }
};