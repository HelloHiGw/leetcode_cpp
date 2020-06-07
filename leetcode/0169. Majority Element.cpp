class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int majority = nums[0];
        int cnt = 1;
        for (int i = 1; i < nums.size(); ++i) {
            if (cnt == 0) {
                majority = nums[i];
                cnt = 1;
            } else if (nums[i] == majority) {
                ++cnt;
            } else {
                --cnt;
            }
        }
        return majority;
    }
};