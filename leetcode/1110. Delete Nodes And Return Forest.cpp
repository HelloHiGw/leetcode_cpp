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
//     vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
//         vector<TreeNode*> res;
//         dfs(root, to_delete, res);
//         if (find(to_delete.begin(), to_delete.end(), root->val) == to_delete.end()) res.push_back(root);
//         return res;
//     }
    
//     TreeNode* dfs(TreeNode* root, vector<int>& to_delete, vector<TreeNode*>& res) {
//         if (!root) return nullptr;
//         root->left = dfs(root->left, to_delete, res);
//         root->right = dfs(root->right, to_delete, res);
//         if (find(to_delete.begin(), to_delete.end(), root->val) != to_delete.end()) {
//             if (root->left) res.push_back(root->left);
//             if (root->right) res.push_back(root->right);
//             return nullptr;
//         }
//         return root;
//     }
// };

class Solution {
public:
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        unordered_set<int> st;
        for (int val : to_delete) {
            st.insert(val);
        }
        vector<TreeNode*> res;
        dfs(root, st, res);
        // do not forget the root
        if (st.find(root->val) == st.end()) res.push_back(root);
        return res;
    }
    
    TreeNode* dfs(TreeNode* root, unordered_set<int>& st, vector<TreeNode*>& res) {
        if (!root) return nullptr;
        root->left = dfs(root->left, st, res);
        root->right = dfs(root->right, st, res);
        if (st.find(root->val) != st.end()) {
            if (root->left) res.push_back(root->left);
            if (root->right) res.push_back(root->right);
            return nullptr;
        }
        return root;
    }
};