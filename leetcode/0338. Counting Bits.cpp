// class Solution {
// public:
//     vector<int> countBits(int num) {
//         vector<int> res;
//         for (int i = 0; i <= num; ++i) {
//             bitset<32> bits(i);
//             res.push_back(bits.count());
//         }
//         return res;
//     }
// };


class Solution {
public:
    vector<int> countBits(int num) {
        vector<int> dp(num + 1, 0);
        for (int i = 1; i <= num; ++i) {
            dp[i] = dp[i / 2] + (i % 2 == 1);
        }
        return dp;
    }
};

// dp[binary string without the last bit] + last bit is 1 or not