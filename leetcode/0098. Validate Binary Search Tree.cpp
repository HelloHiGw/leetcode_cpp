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
//     bool isValidBST(TreeNode* root) {
//         return dfs(root, NULL, NULL);
//     }
  
//     bool dfs(TreeNode* root, TreeNode* minNode, TreeNode* maxNode) {
//         if (!root) return true;
//         if (minNode && minNode->val >= root->val) return false;
//         if (maxNode && maxNode->val <= root->val) return false;
//         return dfs(root->left, minNode, root) && dfs(root->right, root, maxNode);
//     }
// };

class Solution {
public:
    bool isValidBST(TreeNode* root) {
        stack<TreeNode*> st;
        TreeNode* pre = NULL;
        while (!st.empty() || root) {
            while (root) {
            st.push(root);
            root = root->left;
        }
        root = st.top();
        st.pop();
        if (pre && pre->val >= root->val) return false;
        pre = root;
        root = root->right;
        }
        return true;
    }
};