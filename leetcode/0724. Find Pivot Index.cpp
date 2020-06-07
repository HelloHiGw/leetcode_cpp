class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int sum = 0, currSum = 0;
        for (int num : nums) {
            sum += num;
        }
        for (int i = 0; i < nums.size(); ++i) {
            if (currSum * 2 == sum - nums[i]) return i;
            currSum += nums[i];
        }
        return -1;
    }
};