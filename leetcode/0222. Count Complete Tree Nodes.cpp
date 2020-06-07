/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
// height is 0-based
// class Solution {
// public:
//     int countNodes(TreeNode* root) {
//         int hLeft = 0, hRight = 0;
//         TreeNode *left = root, *right = root;
//         while (left) {
//             left = left->left;
//             ++hLeft;
//         }
//         while (right) {
//             right = right->right;
//             ++hRight;
//         }
//         if (hLeft == hRight) return pow(2, hLeft) - 1;
//         return 1 + countNodes(root->left) + countNodes(root->right);
//     }
// };

class Solution {
public:
    int countNodes(TreeNode* root) {
        int h = getHeight(root);
        if (h == 0) return 0;
        int hRight = getHeight(root->right);
        if (hRight == h - 1) return pow(2, h - 1) + countNodes(root->right);
        return pow(2, h - 2) + countNodes(root->left);
    }
    
    int getHeight(TreeNode* root) {
        if (!root) return 0;
        return 1 + getHeight(root->left);
    }
};