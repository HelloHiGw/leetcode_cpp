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
//     TreeNode* lcaDeepestLeaves(TreeNode* root) {
//         return dfs(root).second;
//     }
    
//     pair<int, TreeNode*> dfs(TreeNode* root) {
//         if (!root) return {0, nullptr};
//         auto left = dfs(root->left);
//         auto right = dfs(root->right);
//         int h = max(left.first, right.first) + 1;
//         if (left.first == right.first) return {h, root};
//         return {h, left.first > right.first ? left.second : right.second};
//     }
// };

class Solution {
public:
    TreeNode* lcaDeepestLeaves(TreeNode* root) {
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