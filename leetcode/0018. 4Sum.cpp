class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        return kSum(nums, 0, 4, target);
    }
    
    vector<vector<int>> kSum(vector<int>& nums, int start, int k, int target) {
        vector<vector<int>> res;
        if (k == 2) {
            int end = nums.size() - 1;
            while (start < end) {
                if (nums[start] + nums[end] == target) {
                    vector<int> v{nums[start], nums[end]};
                    res.push_back(v);
                    while (start < end && nums[start] == v[0]) ++start;
                    while (start < end && nums[end] == v[1]) --end;
                } else if (nums[start] + nums[end] < target) {
                    ++start;
                } else {
                    --end;
                }
            }
        } else {
            for (int i = start; i < (int)nums.size() - k + 1; ++i) {
                if (i > start && nums[i] == nums[i - 1]) continue;
                vector<vector<int>> temp = kSum(nums, i + 1, k - 1, target - nums[i]);
                for (auto &v : temp) {
                    v.insert(v.begin(), nums[i]);
                }
                res.insert(res.end(), temp.begin(), temp.end());
            }
        }
        return res;
    }
};