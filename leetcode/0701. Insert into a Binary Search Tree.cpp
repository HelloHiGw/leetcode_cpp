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
//     TreeNode* insertIntoBST(TreeNode* root, int val) {
//         if (!root) return new TreeNode(val);
//         if (root->val > val) {
//             root->left = insertIntoBST(root->left, val);
//         } else {
//             root->right = insertIntoBST(root->right, val);
//         }
//         return root;
//     }
// };


class Solution {
public:
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if (!root) return new TreeNode(val);
        TreeNode* curr = root;
        while (true) {
            if (curr->val > val) {
                if (!curr->left) {
                    curr->left = new TreeNode(val);
                    break;
                }
                curr = curr->left;
            } else {
                if (!curr->right) {
                    curr->right = new TreeNode(val);
                    break;
                }
                curr = curr->right;
            }
        }
        return root;
    }
};