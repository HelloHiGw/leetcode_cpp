/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* insertIntoMaxTree(TreeNode* root, int val) {
        if (!root) return new TreeNode(val);
        TreeNode* node = new TreeNode(val);
        if (root->val < val) {
            node->left = root;
            return node;
        }
        TreeNode* curr = root;
        while (curr->right && curr->right->val > val) {
            curr = curr->right;
        }
        node->left = curr->right;
        curr->right = node;
        return root;
    }
};