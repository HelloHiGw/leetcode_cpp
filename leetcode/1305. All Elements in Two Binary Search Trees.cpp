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
//     vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
//         vector<int> res;
//         stack<TreeNode*> st1, st2;
//         while ((!st1.empty() || root1) && (!st2.empty() || root2)) {
//             while (root1) {
//                 st1.push(root1);
//                 root1 = root1->left;
//             }
//             while (root2) {
//                 st2.push(root2);
//                 root2 = root2->left;
//             }
//             if (st1.top()->val < st2.top()->val) {
//                 root1 = st1.top();
//                 st1.pop();
//                 res.push_back(root1->val);
//                 root1 = root1->right;  
//             } else {
//                 root2 = st2.top();
//                 st2.pop();
//                 res.push_back(root2->val);
//                 root2 = root2->right; 
//             }
//         }
//         inorder(st1, root1, res);
//         inorder(st2, root2, res);
//         return res;
//     }
    
//     void inorder(stack<TreeNode*>& st, TreeNode* root, vector<int>& res) {
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
//     }
// };


class Solution {
public:
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
        vector<int> res;
        stack<TreeNode*> st1, st2;
        pushLeft(root1, st1);
        pushLeft(root2, st2);
        while (!st1.empty() || !st2.empty()) {
            stack<TreeNode*> &st = st2.empty() ? st1 : (st1.empty() ? st2 : (st1.top()->val < st2.top()->val ? st1 : st2));
            TreeNode* root = st.top();
            res.push_back(root->val);
            st.pop();
            root = root->right;
            pushLeft(root, st);
        }
        return res;
    }
    
    void pushLeft(TreeNode* root, stack<TreeNode*>& st) {
        while (root) {
            st.push(root);
            root = root->left;
        }
    }
};

