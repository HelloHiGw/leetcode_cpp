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
    int sumEvenGrandparent(TreeNode* root) {
        return dfs(root, 1, 1);
    }
    
    int dfs(TreeNode* root, int p, int gp) {
        if (!root) return 0;
        return (gp % 2 == 0 ? root->val : 0) + dfs(root->left, root->val, p) + dfs(root->right, root->val, p);
    }
};