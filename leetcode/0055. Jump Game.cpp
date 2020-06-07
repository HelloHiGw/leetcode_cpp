// class Solution {
// public:
//     bool canJump(vector<int>& nums) {
//         int i = 0, n = nums.size();
//         while (i < n - 1) {
//             if (nums[i] == 0) break;
//             if (i + nums[i] >= n - 1) return true;
//             int pos = i + 1;  // optimal next jump postion in current jump range
//             for (int j = i + 1; j <= i + nums[i]; ++j) {
//                 if (j + nums[j] > pos + nums[pos]) pos = j;
//             }
//             i = pos;
//         }
//         return i >= n - 1;
//     }
// };

class Solution {
public:
    bool canJump(vector<int>& nums) {
        int reach = 0, n = nums.size();
        for (int i = 0; i <= reach; ++i) {  // for range(reach) expands with scaning
            reach = max(reach, i + nums[i]);
            if (reach >= n - 1) return true;
        }
        return false;
    }
};