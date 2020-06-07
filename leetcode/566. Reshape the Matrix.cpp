class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& nums, int r, int c) {
        int oriR = nums.size(), oriC = nums[0].size();
        if (oriR * oriC != r * c) return nums;
        vector<vector<int>> res(r, vector<int>(c));
        for (int i = 0; i < r * c; ++i) {
            res[i / c][i % c] = nums[i / oriC][i % oriC];
        }
        return res;
    }
};