// class Solution {
// public:
//     bool hasAlternatingBits(int n) {
//         int lastBit = 2;
//         while (n) {
//             if (lastBit != 2 && (n & 1) == lastBit) return false;
//             lastBit = n & 1;
//             n >>= 1;
//         }
//         return true;
//     }
// };

class Solution {
public:
    bool hasAlternatingBits(int n) {
        long a = n ^ (n >> 1);
        return (a & (a + 1)) == 0;
    }
};

        /*
        n =         1 0 1 0 1 0 1 0
        n >> 1      0 1 0 1 0 1 0 1
        n ^ n>>1    1 1 1 1 1 1 1 1
        n           1 1 1 1 1 1 1 1
        n + 1     1 0 0 0 0 0 0 0 0
        n & (n+1)   0 0 0 0 0 0 0 0
        */