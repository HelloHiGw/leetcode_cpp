/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
// class Solution {
// public:
//     TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
//         return buildTree(nums, 0, nums.size() - 1);
//     }
    
//     TreeNode* buildTree(vector<int>& nums, int start, int end) {
//         if (start > end) return nullptr;
//         int index = start;
//         for (int i = start + 1; i <= end; ++i) {
//             if (nums[i] > nums[index]) index = i;
//         }
//         TreeNode* root = new TreeNode(nums[index]);
//         root->left = buildTree(nums, start, index - 1);
//         root->right = buildTree(nums, index + 1, end);
//         return root;
//     }
// };

// https://leetcode.com/problems/maximum-binary-tree/discuss/106156/Java-worst-case-O(N)-solution
class Solution {
public:
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        vector<TreeNode*> v;
        for (int num : nums) {
            TreeNode* curr = new TreeNode(num);
            while (!v.empty() && v.back()->val < num) {
                curr->left = v.back();
                v.pop_back();
            }
            if (!v.empty()) {
                v.back()->right = curr;
            }
            v.push_back(curr);
        }
        return v.front();
    }
};