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
    int distributeCoins(TreeNode* root) {
        int res = 0;
        dfs(root, res);
        return res;
    }
    
    // return the number of coins given to the parent.
    int dfs(TreeNode* root, int& res) {
        if (!root) return 0;
        int left = dfs(root->left, res), right = dfs(root->right, res);
        res += abs(left) + abs(right);
        return left + right + root->val - 1;
    }
};