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
//     vector<vector<int>> levelOrder(TreeNode* root) {
//         vector<vector<int>> res;
//         dfs(root, 0, res);
//         return res;
//     }
    
//     void dfs(TreeNode* root, int depth, vector<vector<int>>& res) {
//         if (!root) return;
//         if (depth == res.size()) res.push_back({});
//         res[depth].push_back(root->val);
//         dfs(root->left, depth + 1, res);
//         dfs(root->right, depth + 1, res);
//     }
// };


class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        if (!root) return {};
        vector<vector<int>> res;
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
          int size = q.size();
          vector<int> v(size);
          for (int i = 0; i < size; ++i) {
            TreeNode* top = q.front();
            q.pop();
            v[i] = top->val;
            if (top->left) q.push(top->left);
            if (top->right) q.push(top->right);
          }
          res.push_back(v);
        }
        return res;
    }
};