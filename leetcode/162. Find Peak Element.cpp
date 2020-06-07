/*
Lets say you have a mid number at index x, nums[x]
if (num[x+1] > nums[x]), that means a peak element HAS to exist on the right half of that array, 
because (since every number is unique) 
1. the numbers keep increasing on the right side, and the peak will be the last element.
2. the numbers stop increasing and there is a 'dip', or there exists somewhere a number such that
nums[y] < nums[y-1], which means number[y] is a peak element.

the same for nums[x] > nums[x + 1]
*/
class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int left = 0, right = nums.size() - 1;
        while (left < right) {  // clip out the peak
            int mid = left + (right - left) / 2;
            // left < right, mid + 1 at most is right, will not out of right
            if (nums[mid] < nums[mid + 1]) {
                left = mid + 1;
            } else {
                right = mid;
            }
        }
        return left;
    }
};