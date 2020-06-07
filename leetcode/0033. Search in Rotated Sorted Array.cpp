class Solution {
public:
    int search(vector<int>& nums, int target) {
        if (nums.empty()) return -1;
        int minIndex = findMinIndex(nums);
        int n = nums.size();
        
        // either in the first ascending part or the second ascending part
        if (nums.back() < target) {
            return binarySearch(0, minIndex - 1, nums, target);
        } else {
            return binarySearch(minIndex, nums.size() - 1, nums, target);
        }
    }

private:
    int findMinIndex(vector<int>& nums) {
        int left = 0, right = nums.size() - 1, mid;
        while (left < right) {  // clip out the minIndex
            mid = left + (right - left) / 2;
            if (nums[mid] < nums[right]) {  // no duplicates
                right = mid;
            } else {
                left = mid + 1;
            }
        }
        return left;
    }
    
    int binarySearch(int left, int right, vector<int>& nums, int target) {
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] == target) {
                return mid;
            } else if (nums[mid] > target) {
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
        return -1;
    }
};

/*
如果中间的数小于最右边的数，则右半段是有序的，
若中间数大于最右边数，则左半段是有序的
*/
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int left = 0, right = nums.size() - 1, mid;
        while (left <= right) {
            mid = left + (right - left) / 2;
            if (nums[mid] == target) return mid;
            
            if (nums[mid] < nums[right]) {  // the right is ascending
                if (nums[mid] < target && nums[right] >= target) {  // judge whether target is in the right 
                    left = mid + 1;
                } else {
                    right = mid - 1;
                }
            } else {  // the left is ascending
                if (nums[mid] > target && nums[left] <= target) {  // judge whether target is in the left
                    right = mid - 1;
                } else {
                    left = mid + 1;
                }
            }
        }
        return -1;
    }
};