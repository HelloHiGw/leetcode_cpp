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
//     int findBottomLeftValue(TreeNode* root) {
//         int maxDepth = -1;
//         int res = -1;
//         dfs(root, 0 , maxDepth, res);
//         return res;
//     }
    
//     void dfs(TreeNode* root, int depth, int& maxDepth, int& res) {
//         if (!root) return;
//         if (depth > maxDepth) {
//             maxDepth = depth;
//             res = root->val;
//         }
//         dfs(root->left, depth + 1, maxDepth, res);
//         dfs(root->right, depth + 1, maxDepth, res);
//     }
// };

// class Solution {
// public:
//     int findBottomLeftValue(TreeNode* root) {
//         queue<TreeNode*> q;
//         q.push(root);
//         int res = -1;
//         while (!q.empty()) {
//             res = q.front()->val;
//             for (int i = q.size(); i > 0; --i) {
//                 root = q.front();
//                 q.pop();
//                 if (root->left) q.push(root->left);
//                 if (root->right) q.push(root->right);
//             }
//         }
//         return res;
//     }
// };

class Solution {
public:
    int findBottomLeftValue(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            root = q.front();
            q.pop();
            if (root->right) q.push(root->right);
            if (root->left) q.push(root->left);
        }
        return root->val;
    }
};