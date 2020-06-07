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
//     bool isCompleteTree(TreeNode* root) {
//         if (!root) return true;
//         int count = 0, maxIndex = 0;
//         dfs(root, 1, maxIndex, count);
//         return count == maxIndex;
//     }
//     // int overflow
//     void dfs(TreeNode* root, int index, int& maxIndex, int& count) {
//         if (!root) return;
//         ++count;
//         maxIndex = max(maxIndex, index);
//         dfs(root->left, 2 * index, maxIndex, count);
//         dfs(root->right, 2 * index + 1, maxIndex, count);
//     }
// };

class Solution {
public:
    bool isCompleteTree(TreeNode* root) {
        if (!root) return true;
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            for (int i = q.size(); i > 0; --i) {
                root = q.front();
                q.pop();
                if (!root) {
                    while (!q.empty()) {
                        TreeNode* t = q.front();
                        q.pop();
                        if (t) return false;
                    }
                    return true;
                }
                q.push(root->left);
                q.push(root->right);
            }
        }
        return true;
    }
};