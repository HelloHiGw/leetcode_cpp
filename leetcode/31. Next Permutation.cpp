class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int i = 0, n = nums.size();
        for (i = n - 2; i >= 0; --i) {
            if (nums[i] < nums[i + 1]) break;
        }
        if (i == -1) {
            reverse(nums.begin(), nums.end());
        } else {
            for (int j = n - 1; j > i; --j) {
                if (nums[j] > nums[i]) {
                    swap(nums[j], nums[i]);
                    reverse(nums.begin() + i + 1, nums.end());  // equals to sort, but it is descending, use reverse, which is faster
                    break;
                }
            }
        }
    }
};

// https://leetcode.com/problems/next-permutation/discuss/13867/C%2B%2B-from-Wikipedia
// the first comment