// class Solution {
// public:
//     string toHex(int num) {
//         if (num == 0) return "0";
//         unsigned int n = num;
//         if (num < 0) n = UINT_MAX + num + 1;
//
//         string hex = "0123456789abcdef";
//         string res;
//
//         while (n) {
//             int remainder = n % 16;
//             res += hex[remainder];
//             n /= 16;
//         }
//         reverse(res.begin(), res.end());
//         return res;
//     }
// };


class Solution {
public:
    string toHex(int num) {
        if (num == 0) return "0";
        unsigned int n = num;  // negative int to unsigned int, just as the above
        
        string hex = "0123456789abcdef";
        string res;
        
        while (n) {
            int remainder = n % 16;
            res += hex[remainder];
            n /= 16;
        }
        reverse(res.begin(), res.end());
        return res;
    }
};


