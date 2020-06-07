// class Solution {
// public:
//     int findComplement(int num) {
//         int res = 0;
//         long base = 1;
//         while (num) {
//             res = ((num & 1) == 0) * base + res;
//             base <<= 1;
//             num >>= 1;
//         }
//         return res;
//     }
// };

class Solution {
public:
    int findComplement(int num) {
        unsigned int mask = ~0;
        while (mask & num) mask <<= 1;
        return ~mask & ~num;
        // return ~mask ^ num;
    }
};

/*

num          = 00000101
mask         = 11111000
~mask & ~num = 00000010

*/


class Solution {
public:
    int findComplement(int num) {
        int n = 0;
        while (n < num) {
            n = (n << 1) | 1;
        }
        // return n - num;
        return n ^ num;
    }
};


/*
num          = 00000101
n            = 00000111
n ^ num      = 00000010
*/