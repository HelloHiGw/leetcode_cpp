// class Solution {
// public:
//     vector<string> readBinaryWatch(int num) {
//         vector<int> hour = {1, 2, 4, 8};
//         vector<int> minute = {1, 2, 4, 8, 16, 32};
//         vector<string> res;
//         for (int i = 0; i <= num; ++i) {
//             vector<int> h;
//             generate(hour, i, 0, 0, h);
//             vector<int> m;
//             generate(minute, num - i, 0, 0, m);
//             for (int a : h){
//                 if (a > 11) continue;
//                 for (int b : m) {
//                     if (b > 59) continue;
//                     string s = to_string(a) + (b < 10 ? ":0" : ":") + to_string(b);
//                     res.push_back(s);
//                 }
//             }
//         }
//         return res;
//     }
    
//     void generate(vector<int>& nums, int k, int start, int curr, vector<int>& res) {
//         if (k == 0) {
//             res.push_back(curr);
//             return;
//         }
//         // constraint function
//         if (start + k - 1 >= nums.size()) return;
//         for (int i = start; i < nums.size(); ++i) {
//             generate(nums, k - 1, i + 1, curr + nums[i], res);
//         }
//     }
// };


class Solution {
public:
    vector<string> readBinaryWatch(int num) {
        vector<string> res;
        for (int h = 0; h < 12; ++h) {
            for (int m = 0; m < 60; ++m) {
                bitset<10> bs((h << 6) + m);
                if (bs.count() == num) {
                    string s = to_string(h) + (m < 10 ? ":0" : ":") + to_string(m);
                    res.push_back(s);
                }
            }
        }
        return res;
    }
};