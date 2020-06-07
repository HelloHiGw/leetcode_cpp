class Solution {
public:
    int findShortestSubArray(vector<int>& nums) {
        unordered_map<int, int> count, firstIndex;
        int degree = -1, res = -1;
        for (int i = 0; i < nums.size(); ++i) {
            if (firstIndex.find(nums[i]) == firstIndex.end()) firstIndex[nums[i]] = i;
            count[nums[i]] += 1;
            if (count[nums[i]] > degree) {
                degree = count[nums[i]];
                res = i - firstIndex[nums[i]] + 1;
            } else if (count[nums[i]] == degree) {
                res = min(res, i - firstIndex[nums[i]] + 1);
            }
        }
        return res;
    }
};