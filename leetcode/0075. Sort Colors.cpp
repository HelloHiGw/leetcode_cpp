class Solution {
public:
    void sortColors(vector<int>& nums) {
        int low = 0, high = nums.size() - 1;
        int curr = 0;
        while (curr <= high) {
            if (nums[curr] == 0) {
                swap(nums[curr], nums[low]);
                ++low;
                ++curr;
            } else if (nums[curr] == 2) {
                swap(nums[curr], nums[high]);
                --high;
            } else {
                ++curr;
            }
        }
    }
};

/*
0 to low - 1 are 0s
high + 1 to  n - 1 are 2s

when nums[curr] = 2, we swap(nums[curr], nums[high]), --high
curr must not ++, because we have not tackle with swapped nums[curr]
i.e. we don't know the original A[high] is what number.

when nums[curr] = 1, we swap(nums[curr], nums[low]), ++low
curr must ++, because nums[low] must be 0 or 1, both case needs ++curr
(curr runs faster than low, curr has put 2 to the end, there is no 2 in the range [0, curr])

considering 1 1 1 0 0 0, low = 0, curr = 3
considering 0 0 0 1 1 1, low = 0, curr = 0
*/