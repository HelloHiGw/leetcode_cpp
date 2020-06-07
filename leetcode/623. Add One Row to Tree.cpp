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
//     TreeNode* addOneRow(TreeNode* root, int v, int d) {
//         if (d == 1) {
//             TreeNode* node = new TreeNode(v);
//             node->left = root;
//             return node;
//         }
//         dfs(root, v, d, 1);
//         return root;
//     }
    
//     void dfs(TreeNode* root, int v, int d, int depth) {
//         if (!root) return;
//         if (depth == d - 1) {
//             TreeNode* left = new TreeNode(v);
//             TreeNode* right = new TreeNode(v);
//             left->left = root->left;
//             right->right = root->right;
//             root->left = left;
//             root->right = right;
//             return;
//         }
//         dfs(root->left, v, d, depth + 1);
//         dfs(root->right, v, d, depth + 1);
//     }
// };

class Solution {
public:
    TreeNode* addOneRow(TreeNode* root, int v, int d) {
        return dfs(root, v, d, true);
    }
    
    TreeNode* dfs(TreeNode* root, int v, int d, bool isLeft) {
        if (d == 1) {
            TreeNode* node = new TreeNode(v);
            (isLeft ? node->left : node->right) = root;
            return node;
        }
        if (!root) return nullptr;
        root->left = dfs(root->left, v, d - 1, true);
        root->right = dfs(root->right, v, d - 1, false);
        return root;
    }
};