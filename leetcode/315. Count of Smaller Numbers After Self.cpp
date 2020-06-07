// //In theory it is O(n^2) but C++ insertion of vector optimized it.
// // do not use binary serch and v.insert() to optimize, TLE
// class Solution {
// public:
//     vector<int> countSmaller(vector<int>& nums) {
//         vector<int> v, res(nums.size());
//         for (int i = nums.size() - 1; i >= 0; --i) {
//             int index = lowerBound(v, nums[i]);
//             res[i] = index;
//             v.insert(v.begin() + index, nums[i]);  // naive swap from right to index, TLE
//         }
//         return res;
//     }
    
//     int lowerBound(vector<int>& v, int target) {  // smaller, so is lowerBound. smaller or equal is upperBound
//         int low = 0, high = v.size();
//         while (low < high) {
//             int mid = low + (high - low) / 2;
//             if (v[mid] >= target) {
//                 high = mid;
//             } else {
//                 low = mid + 1;
//             }
//         }
//         return low;
//     }
// };



// O(n^2) in worst case 5 4 3 2 1
// class Solution {
    
// struct TreeNode {
//     int val;
//     int sum;  // the count of leftSubtree + 1 (root self)
//     TreeNode *left, *right;
//     TreeNode(int _val, int _sum) : val(_val), sum(_sum), left(nullptr), right(nullptr) {}
// };
    
// public:    
//     vector<int> countSmaller(vector<int>& nums) {
//         vector<int> res;
//         TreeNode *root = nullptr;
//         for (int i = nums.size() - 1; i >= 0; --i) {
//             root = insert(root, nums[i], 0, res);
//         }
//         reverse(res.begin(), res.end());
//         return res;
//     }
    
//     // cnt denotes the smaller num in the right array, when to the right, we add root->sum
//     TreeNode* insert(TreeNode* root, int val, int cnt, vector<int>& res) {
//         if (!root) {
//             res.push_back(cnt);  // the ans we want
//             return new TreeNode(val, 1);  // leaf sum = 1
//         }
//         if (root->val >= val) { // equal, go to the left, equal don't take into cnt
//             root->left = insert(root->left, val, cnt, res);
//             ++root->sum;
//         } else {
//             root->right = insert(root->right, val, cnt + root->sum, res);
//         }
//         return root;
//     }
// };


class Solution {
public:
    vector<int> countSmaller(vector<int>& nums) {
        vector<int> index(nums.size()), temp(nums.size()), res(nums.size());
        for (int i = 0; i < index.size(); ++i) {
            index[i] = i;
        }
        mergeCount(index, temp, 0, nums.size() - 1, nums, res);
        return res;
    }
    
    void mergeCount(vector<int>& index, vector<int>& temp, int start, int end, vector<int>& nums, vector<int>& res) {
        if (start >= end) return;
        int mid = start + (end - start) / 2;
        mergeCount(index, temp, start, mid, nums, res); // the index of the sorted array
        mergeCount(index, temp, mid + 1, end, nums, res);
        int i = start, j = mid + 1, k = start;
        int count = 0;
        while (i <= mid || j <= end) {
            if (j > end || i <= mid && nums[index[i]] <= nums[index[j]]) {
                res[index[i]] += count;  // here we need index to increase the rightCount of the current num, so normal mergesort of return array is unadvisable
                temp[k++] = index[i++];
            } else {
                temp[k++] = index[j++];
                ++count;
            }
        }
        for (int i = start; i <= end; ++i) {
            index[i] = temp[i];
        }
    }
};