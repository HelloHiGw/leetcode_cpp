class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        double sum = 0, res =  -DBL_MAX;
        for (int i = 0; i < nums.size(); ++i) {
            sum += nums[i];
            if ( i >= k - 1) {
                res = max(res, sum / k);
                sum -= nums[i - k + 1];
            }
        }
        return res;
    }
};