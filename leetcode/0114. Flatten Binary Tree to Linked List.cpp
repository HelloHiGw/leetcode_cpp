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
//     void flatten(TreeNode* root) {
//         TreeNode* pre = nullptr;
//         dfs(root, pre);
//     }
    
//     void dfs(TreeNode* root, TreeNode*& pre) {
//         if (!root) return;
//         TreeNode* left = root->left;
//         TreeNode* right = root->right;
//         root->left = root->right = nullptr;
//         if (pre) pre->right = root;
//         pre = root;
//         dfs(left, pre);
//         dfs(right, pre);
//     }
// };

// O(NlgN) ? 
// class Solution {
// public:
//     void flatten(TreeNode* root) {
//         if (!root) return;
//         flatten(root->left);
//         flatten(root->right);
//         TreeNode* right = root->right;
//         root->right = root->left;
//         root->left = nullptr;
//         while (root->right) root = root->right;
//         root->right = right;
//     }
// };


// class Solution {
// public:
//     void flatten(TreeNode* root) {
//         while (root) {
//             if (root->left) {
//                 TreeNode* p = root->left;
//                 while (p->right) p = p->right;
//                 p->right = root->right;
//                 root->right = root->left;
//                 root->left = nullptr;
//             }
//             root = root->right;
//         }
//     }
// };

class Solution {
public:
    void flatten(TreeNode* root) {
        TreeNode* pre = nullptr;
        dfs(root, pre);
    }
    
    void dfs(TreeNode* root, TreeNode*& pre) {
        if (!root) return;
        dfs(root->right, pre);
        dfs(root->left, pre);
        root->left = nullptr;
        root->right = pre;
        pre = root;
    }
};