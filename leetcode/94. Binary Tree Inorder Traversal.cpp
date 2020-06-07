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
//     vector<int> inorderTraversal(TreeNode* root) {
//         vector<int> res;
//         dfs(root, res);
//         return res;
//     }
    
//     void dfs(TreeNode* root, vector<int>& res) {
//         if (!root) return;
//         dfs(root->left, res);
//         res.push_back(root->val);
//         dfs(root->right, res);
//     }
// };

// class Solution {
// public:
//     vector<int> inorderTraversal(TreeNode* root) {
//         vector<int> res;
//         stack<TreeNode*> st;
//         while (!st.empty() || root) {
//             while (root) {
//                 st.push(root);
//                 root = root->left;
//             }
//             root = st.top();
//             st.pop();
//             res.push_back(root->val);
//             root = root->right;
//         }
//         return res;
//     }
// };


class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> res;
        TreeNode* pre = nullptr;
        while (root) {
            if (!root->left) {
                res.push_back(root->val);
                root = root->right;
            } else {
                pre = root->left;
                while (pre->right && pre->right != root) pre = pre->right;
                if (!pre->right) {
                    pre->right = root;
                    root = root->left;
                } else {
                    res.push_back(root->val);
                    pre->right = nullptr;
                    root = root->right;
                }
            }
        }
        return res;
    }
};