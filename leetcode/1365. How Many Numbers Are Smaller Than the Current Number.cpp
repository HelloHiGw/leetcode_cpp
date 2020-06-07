class Solution {
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
        vector<int> count(101);
        for (int num : nums) {
            ++count[num];
        }
        int left = 0;
        for (int i = 0; i < 101; ++i) {
            int temp = count[i];
            count[i] = left;
            left += temp;
        }
        vector<int> res(nums.size());
        for (int i = 0; i < nums.size(); ++i) {
            res[i] = count[nums[i]];
        }
        return res;
    }
};