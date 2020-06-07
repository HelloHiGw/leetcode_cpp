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
    int longestZigZag(TreeNode* root) {
        int res = 0;
        dfs(root, res);
        return res;
    }
    
    pair<int, int> dfs(TreeNode* root, int& res) {
        if (!root) return {-1, -1};
        auto left = dfs(root->left, res), right = dfs(root->right, res);
        int curr = max(left.second, right.first) + 1;
        res = max(res, curr);
        return {left.second + 1, right.first + 1};
    }
};