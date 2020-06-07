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
//     vector<int> postorderTraversal(TreeNode* root) {
//         vector<int> v;
//         postorder(root, v);
//         return v;
//     }
    
//     void postorder(TreeNode *root, vector<int>& v) {
//         if (!root) return;
//         postorder(root->left, v);
//         postorder(root->right, v);
//         v.push_back(root->val);
//     }
// };

// class Solution {
// public:
//     vector<int> postorderTraversal(TreeNode* root) {
//         if (!root) return {};
//         stack<TreeNode*> st;
//         st.push(root);
//         vector<int> v;
//         while (!st.empty()) {
//             root = st.top();
//             st.pop();
//             v.push_back(root->val);
//             if (root->left) st.push(root->left);
//             if (root->right) st.push(root->right);
//         }
//         reverse(v.begin(), v.end());
//         return v;
//     }
// };

// class Solution {
// public:
//     vector<int> postorderTraversal(TreeNode* root) {
//         stack<TreeNode*> st;
//         vector<int> v;
//         while (!st.empty() || root) {
//             while (root) {
//                 st.push(root);
//                 v.push_back(root->val);
//                 root = root->right;
//             }
//             root = st.top();
//             st.pop();
//             root = root->left;
//         }
//         reverse(v.begin(), v.end());
//         return v;
//     }
// };


class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        if (!root) return {};
        stack<TreeNode*> st;
        st.push(root);
        TreeNode *pre = root;  // pre can not be initialized as nullptr, consider 1 null 2, it goes wrong
        vector<int> v;
        while (!st.empty()) {
            root = st.top();
            // st as following, root->left = pre denotes root->right = nullptr
            // left (pre)
            // right (pre)
            // root
            if (!root->left && !root->right || root->left == pre || root->right == pre) {
                v.push_back(root->val);
                st.pop();  // only after visiting left and right, pop
                pre = root;
            } else {
                if (root->right) st.push(root->right);
                if (root->left) st.push(root->left);
            }
        }
        return v;
    }
};