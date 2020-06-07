// class Solution {
// public:
//     vector<int> createTargetArray(vector<int>& nums, vector<int>& index) {
//         vector<int> res;
//         for (int i = 0; i < index.size(); ++i) {
//             res.insert(res.begin() + index[i], nums[i]);
//         }
//         return res;
//     }
// };


class Solution {
public:
    vector<int> createTargetArray(vector<int>& nums, vector<int>& index) {
        vector<int> arr(index.size()), temp(index.size());
        for (int i = 0; i < arr.size(); ++i) {
            arr[i] = i;
        }
        mergeCount(arr, temp, 0, arr.size() - 1, index);
        vector<int> res(nums.size());
        for (int i = 0; i < index.size(); ++i) {
            res[index[i]] = nums[i];
        }
        return res;
    }
    
    void mergeCount(vector<int>& arr, vector<int>& temp, int start, int end, vector<int>& index) {
        if (start >= end) return;
        int mid = start + (end - start) / 2;
        mergeCount(arr, temp, start, mid, index);
        mergeCount(arr, temp, mid + 1, end, index);
        int i = start, j = mid + 1, k = start;
        int count = 0;
        while (i <= mid || j <= end) {
            /* 
            take index = {1, 5, 3, 6, ....} as an example
            left = 1, 5 right = 3, 6
            when sorted = 1, 3,  count = 1
            if you do not increase the count (+ count)immediately, you compare 5 with 6, the result will be 1, 6, 3, 6
            however, the turth is compare 6 with 6, which is 1, 7, 3, 6
            */
            if (j > end || i <= mid && index[arr[i]] + count < index[arr[j]]) {
                index[arr[i]] += count;
                temp[k++] = arr[i++];
            } else {
                ++count;
                temp[k++] = arr[j++];
            }
        }
        for (int i = start; i <= end; ++i) {
            arr[i] = temp[i];
        }
    }
};