// class Solution {
// public:
//     int hammingDistance(int x, int y) {
//         return bitset<32>(x ^ y).count();
//     }
// };

class Solution {
public:
    int hammingDistance(int x, int y) {
        int xorr = x ^ y;
        int res = 0;
        while (xorr) {
            res += xorr & 1;
            xorr >>= 1;
        }
        return res;
    }
};