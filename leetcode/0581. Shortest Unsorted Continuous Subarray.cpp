class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        int start = -1, end = -1;
        int maxVal = nums.front(), minVal = nums.back();
        for (int i = 1; i < nums.size(); ++i) {
            if (maxVal > nums[i]) end = i;
            maxVal = max(maxVal, nums[i]);
            if (minVal < nums[nums.size() - 1 - i]) start = nums.size() - 1 - i;
            minVal = min(minVal, nums[nums.size() - 1 - i]);
        }
        return start < end ? end - start + 1 : 0;
    }
};