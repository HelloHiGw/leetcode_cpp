class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        int left = 0, right = 0;
        int sum = 0;
        int res = INT_MAX;
        
        while (right < nums.size()) {
            sum += nums[right];
            ++right;
            
            while (sum >= s) {
                res = min(res, right - left);
                sum -= nums[left];
                ++left;
            }
        }
        
        return res == INT_MAX ? 0 : res;
    }
};