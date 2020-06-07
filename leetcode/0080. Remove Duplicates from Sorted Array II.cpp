// class Solution {
// public:
//     int removeDuplicates(vector<int>& nums) {
//         int len = 0;
//         for (int i = 0, j = 0; i < nums.size(); i = j) {
//             for (j = i; j < nums.size() && nums[j] == nums[i]; ++j);
//             nums[len++] = nums[i];
//             if (j - i >= 2) nums[len++] = nums[i];
//         }
//         return len;
//     }
// };

// class Solution {
// public:
//     int removeDuplicates(vector<int>& nums) {
//         int len = 0;
//         for (int i = 0; i < nums.size(); ++i) {
//             if (len < 2 || nums[i] > nums[len - 2]) nums[len++] = nums[i];
//         }
//         return len;
//     }
// };


// generate to k
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int len = 0;
        int k = 2;
        for (int i = 0; i < nums.size(); ++i) {
            if (len < k || nums[i] > nums[len - k]) nums[len++] = nums[i];
        }
        return len;
    }
};