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
//     int deepestLeavesSum(TreeNode* root) {
//         return dfs(root).second;
//     }
    
//     pair<int, int> dfs(TreeNode* root) {
//         if (!root) return {0, 0};
//         if (!root->left && !root->right) return {1, root->val};
//         auto left = dfs(root->left), right = dfs(root->right);
//         int d1 = left.first, d2 = right.first;
//         if (d1 == d2) return {max(d1, d2) + 1, left.second + right.second};
//         return {max(d1, d2) + 1, d1 > d2 ? left.second : right.second};
//     }
// };

class Solution {
public:
    int deepestLeavesSum(TreeNode* root) {
        if (!root) return 0;
        queue<TreeNode*> q;
        q.push(root);
        int res = 0;
        while (!q.empty()) {
            res = 0;
            for (int i = q.size(); i > 0; --i) {
                root = q.front();
                q.pop();
                res += root->val;
                if (root->left) q.push(root->left);
                if (root->right) q.push(root->right);
            }
        }
        return res;
    }
};