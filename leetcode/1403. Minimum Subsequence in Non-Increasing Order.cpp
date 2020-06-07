// class Solution {
// public:
//     vector<int> minSubsequence(vector<int>& nums) {
//         sort(nums.begin(), nums.end(), cmp);
//         int total = 0;
//         for (int num : nums) total += num;
//         int curr = 0;
//         vector<int> res;
//         for (int num : nums) {
//             curr += num;
//             res.push_back(num);
//             if (curr > total - curr) break;
//         }
//         return res;
//     }
    
// private:
//     static bool cmp(int a, int b) {
//         return a > b;
//     }
// };

class Solution {
public:
    vector<int> minSubsequence(vector<int>& nums) {
        vector<int> count(101);
        int total = 0;
        for (int num : nums) {
            ++count[num];
            total += num;
        }
        int curr = 0;
        vector<int> res;
        for (int i = 100; i >= 0; --i) {
            while (count[i]) {
                curr += i;
                res.push_back(i);
                --count[i];
                if (curr > total - curr) return res;
            }
        }
        return res;
    }
};