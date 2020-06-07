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
//     vector<int> rightSideView(TreeNode* root) {
//         vector<int> res;
//         dfs(root, 0, res);
//         return res;
//     }
    
//     void dfs(TreeNode* root, int depth, vector<int>& res) {
//         if (!root) return;
//         if (depth == res.size()) res.push_back(root->val);
//         dfs(root->right, depth + 1, res);
//         dfs(root->left, depth + 1, res);
//     }
// };

class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        vector<int> res;
        if (!root) return res;
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            res.push_back(q.back()->val);
            for (int i = q.size(); i > 0; --i) {
                root = q.front();
                q.pop();
                if (root->left) q.push(root->left);
                if (root->right) q.push(root->right);
            }
        }
        return res;
    }
};