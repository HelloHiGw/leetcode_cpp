class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int res = -1, minDiff = INT_MAX;
        for (int i = 0; i < (int)nums.size() - 2; ++i) {
            if (i && nums[i] == nums[i - 1]) continue;
            if (nums[i] * 3 > target) {  // prune
                int sum = nums[i] + nums[i + 1] + nums[i + 2], diff = abs(sum - target);
                if (diff < minDiff) {
                    minDiff = diff;
                    res = sum;
                }
                break;
            }
            int start = i + 1, end = nums.size() - 1;
            while (start < end) {
                int sum = nums[i] + nums[start] + nums[end], diff = abs(sum - target);
                if (diff == 0) return target;
                if (diff < minDiff) {
                    minDiff = diff;
                    res = sum;
                }
                sum < target ? ++start : --end;
            }
        }
        return res;        
    }
};