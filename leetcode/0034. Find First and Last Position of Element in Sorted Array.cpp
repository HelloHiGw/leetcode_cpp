// class Solution {
// public:
//     vector<int> searchRange(vector<int>& nums, int target) {
//         int i = lower_bound(nums.begin(), nums.end(), target) - nums.begin();
//         if (i == nums.size() || nums[i] != target) return {-1, -1};
//         int j = upper_bound(nums.begin(), nums.end(), target) - nums.begin();
//         return {i, j - 1};
//     }
// };


class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int i = lowerBound(nums, target);
        if (i == nums.size() || nums[i] != target) return {-1, -1};
        int j = upperBound(nums, target);
        return {i, j - 1};
    }
    
    int lowerBound(vector<int>& nums, int target) {
        int low = 0, high = nums.size();
        while (low < high) {
            int mid = low + (high - low) / 2;
            if (nums[mid] >= target) {
                high = mid;
            } else {
                low = mid + 1;
            }
        }
        return low;
    }
    
    int upperBound(vector<int>& nums, int target) {
        int low = 0, high = nums.size();
        while (low < high) {
            int mid = low + (high - low) / 2;
            if (nums[mid] > target) {
                high = mid;
            } else {
                low = mid + 1;
            }
        }
        return low;
    }
};