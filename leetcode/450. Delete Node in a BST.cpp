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
//     TreeNode* deleteNode(TreeNode* root, int key) {
//         if (!root) return nullptr;
//         if (root->val > key) {
//             root->left = deleteNode(root->left, key);
//         } else if (root->val < key) {
//             root->right = deleteNode(root->right, key);
//         } else {
//             if (!root->left) return root->right;
//             if (!root->right) return root->left;
//             TreeNode* curr = root->right;
//             while (curr->left) curr = curr->left;
//             root->val = curr->val;
//             root->right = deleteNode(root->right, curr->val);  
//         }
//         return root;
//     }
// };

// class Solution {
// public:
//     TreeNode* deleteNode(TreeNode* root, int key) {
//         if (!root) return nullptr;
//         if (root->val > key) {
//             root->left = deleteNode(root->left, key);
//         } else if (root->val < key) {
//             root->right = deleteNode(root->right, key);
//         } else {
//             if (!root->left) return root->right;
//             if (!root->right) return root->left;
//             TreeNode* curr = root->right;
//             while (curr->left) curr = curr->left;
//             curr->left = root->left;
//             return root->right;    
//         }
//         return root;
//     }
// };

class Solution {
public:
    TreeNode* deleteNode(TreeNode* root, int key) {
        TreeNode *curr = root, *parent = nullptr;
        while (curr && curr->val != key) {
            parent = curr;
            if (curr->val > key) {
                curr = curr->left;
            } else {
                curr = curr->right;
            }
        }
        if (!parent) {
            return del(curr);
        } else if (parent->left == curr) {
            parent->left = del(curr);
        } else {
            parent->right = del(curr);
        }   
        return root;
    }

    TreeNode* del(TreeNode* root) {
        if (!root) return nullptr;  // key not found
        if (!root->left) return root->right;
        if (!root->right) return root->left;
        TreeNode* curr = root->right;
        while (curr->left) curr = curr->left;
        curr->left = root->left;
        return root->right;
    }
};