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
    int maxProduct(TreeNode* root) {
        long long total = 0, res = 0;
        total = dfs(root, total, res);
        dfs(root, total, res);
        return res % (int)(1e9 + 7);
    }
    
    long long dfs(TreeNode* root, long long total, long long& res) {
        if (!root) return 0;
        long long curr = root->val + dfs(root->left, total, res) + dfs(root->right, total, res);
        res = max(res, curr * (total - curr));
        return curr;
    }
};