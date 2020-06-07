class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int left = 0, right = nums.size() - 1, mid;
        while (left <= right) {
            mid = left + (right - left) / 2;
            if (nums[mid] == target) return true;
            
            if (nums[mid] < nums[right]) {  // right ascending
                if (nums[mid] < target && nums[right] >= target) {
                    left = mid + 1;
                } else {
                    right = mid - 1;
                }
            } else if (nums[left] < nums[mid]) {  // left ascending
                if (nums[left] <= target && nums[mid] > target) {
                    right = mid - 1;
                } else {
                    left = mid + 1;
                }
            } else {
                // equal case, nums[mid] was not the answer, just skip
                if (nums[left] == nums[mid]) ++left;
                if (nums[right] == nums[mid]) --right;
            }
        }
        return false;
    }
};