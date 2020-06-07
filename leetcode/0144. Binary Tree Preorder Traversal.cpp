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
//     vector<int> preorderTraversal(TreeNode* root) {
//         vector<int> res;
//         stack<TreeNode*> st;
//         while (!st.empty() || root) {
//             while (root) {
//                 res.push_back(root->val);
//                 st.push(root);
//                 root = root->left;
//             }
//             root = st.top();
//             root = root->right;
//             st.pop();
//         }
//         return res;
//     }
// };

// class Solution {
// public:
//     vector<int> preorderTraversal(TreeNode* root) {
//         vector<int> res;
//         if (!root) return res;
//         stack<TreeNode*> st;
//         st.push(root);
//         while (!st.empty()) {
//             root = st.top();
//             st.pop();
//             res.push_back(root->val);
//             if (root->right) st.push(root->right);
//             if (root->left) st.push(root->left);
//         }
//         return res;
//     }
// };


class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
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
                    res.push_back(root->val);
                    pre->right = root;
                    root = root->left;
                } else {
                    root = root->right;
                    pre->right = nullptr;
                }
            }
        }
        return res;
    }
};