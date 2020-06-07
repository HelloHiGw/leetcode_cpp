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
    bool isBalanced(TreeNode* root) {
        return dfs(root) != -1;
    }
    
    int dfs(TreeNode* root) {
        if (!root) return 0;
        int leftHeight = dfs(root->left);
        int rightHeight = dfs(root->right);
        if (leftHeight == -1 || rightHeight == -1) return -1;
        if (abs(leftHeight - rightHeight) > 1) return -1;
        return max(leftHeight, rightHeight) + 1;
    }
};