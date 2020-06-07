/*
very similar to max subarray sum
current max product is related to previous max product if current > 0
current max product is related to previous min product if current < 0
*/
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        if (nums.empty()) return 0;
        vector<int> maxP(nums.size()), minP(nums.size());  // maxP and minP ending at index i
        maxP[0] = minP[0] = nums[0];
        int res = nums[0];
        for (int i = 1; i < nums.size(); ++i) {
            if (nums[i] >= 0) {
                maxP[i] = max(maxP[i - 1] * nums[i], nums[i]);
                minP[i] = min(minP[i - 1] * nums[i], nums[i]);
            } else {
                maxP[i] = max(minP[i - 1] * nums[i], nums[i]);
                minP[i] = min(maxP[i - 1] * nums[i], nums[i]);
            }
            res = max(res, maxP[i]);
        }
        return res;
    }
};

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        if (nums.empty()) return 0;
        int res = nums[0], maxP = nums[0], minP = nums[0];
        for (int i = 1; i < nums.size(); ++i) {
            if (nums[i] < 0) swap(maxP, minP);
            maxP = max(maxP * nums[i], nums[i]);
            minP = min(minP * nums[i], nums[i]);
            res = max(res, maxP);
        }
        return res;
    }
};