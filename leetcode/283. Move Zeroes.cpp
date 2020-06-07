// class Solution {
// public:
//     void moveZeroes(vector<int>& nums) {
//         int cnt = 0;
//         for (int i = 0; i < nums.size(); ++i) {
//             if (nums[i] == 0) {
//                 ++cnt;
//             } else {
//                 nums[i - cnt] = nums[i];
//             }
//         }
//         for (int i = nums.size() - cnt; i < nums.size(); ++i) {
//             nums[i] = 0;
//         }
//     }
// };

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int idx = 0;
        for (int num : nums) {
            if (num != 0) nums[idx++] = num;
        }
        for (int i = idx; i < nums.size(); ++i) {
            nums[i] = 0;
        }
    }
};