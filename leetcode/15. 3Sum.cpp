class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> res;
        for (int i = 0; i < (int)nums.size() - 2; ++i) {
            if (i && nums[i] == nums[i - 1]) continue;  // prune nums[i] duplicates
            if (nums[i] > 0) break;
            int target = -nums[i];
            int start = i + 1, end = nums.size() - 1;
            while (start < end) {
                if (nums[start] + nums[end] < target) {
                    ++start;
                } else if (nums[start] + nums[end] > target) {
                    --end;
                } else {
                    vector<int> v{nums[i], nums[start], nums[end]};
                    res.push_back(v);
                    // prune nums[start], nums[end] duplicates
                    while (start < end && nums[start] == v[1]) ++start;
                    while (start < end && nums[end] == v[2]) --end;
                }
            }
        }
        return res;
    }
};