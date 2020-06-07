// class Solution {
// public:
//     int hammingWeight(uint32_t n) {
//         return bitset<32>(n).count();
//     }
// };

// class Solution {
// public:
//     int hammingWeight(uint32_t n) {
//         int res = 0;
//         while (n) {
//             res += n & 1;
//             n >>= 1;
//         }
//         return res;
//     }
// };

/*
n & (n - 1) drops the lowest set bit
n           = 00101100, 
n - 1       = 00101011,
n & (n - 1) = 00101000
*/
class Solution {
public:
    // return the number of '1' bits it has
    int hammingWeight(uint32_t n) {
        int res = 0;
        while (n) {
            n &= n - 1;
            ++res;
        }
        return res;
    }
};