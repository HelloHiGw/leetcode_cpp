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
//     TreeNode* subtreeWithAllDeepest(TreeNode* root) {
//         return dfs(root).second;
//     }
    
//     pair<int, TreeNode*> dfs(TreeNode* root) {
//         if (!root) return {0, nullptr};
//         pair<int, TreeNode*> left = dfs(root->left), right = dfs(root->right);
//         int d1 = left.first, d2 = right.first;
//         return {max(d1, d2) + 1, d1 == d2 ? root : (d1 > d2 ? left.second : right.second)};
//     }
// };

class Solution {
public:
    TreeNode* subtreeWithAllDeepest(TreeNode* root) {
        int maxDepth = -1;
        TreeNode* res = nullptr;
        dfs(root, 0, maxDepth, res);
        return res;
    }
    
    int dfs(TreeNode* root, int depth, int& maxDepth, TreeNode*& res) {
        maxDepth = max(depth, maxDepth);
        if (!root) return depth;
        int left = dfs(root->left, depth + 1, maxDepth, res);
        int right = dfs(root->right, depth + 1, maxDepth, res);
        if (left == maxDepth && right == maxDepth) res = root;
        return max(left, right);
    }
};