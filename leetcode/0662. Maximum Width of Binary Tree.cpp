/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    int widthOfBinaryTree(TreeNode* root) {
        if (!root) return 0;
        queue<pair<TreeNode*, int>> q;
        q.push({root, 1});
        int res = -1;
        while (!q.empty()) {
            // avoid end * 2 overflow, not influence the following, as if a new root
            if (q.size() == 1) q.front().second = 1;
            int start = q.front().second, end = start;
            for (int i = q.size(); i > 0; --i) {
                root = q.front().first;
                end = q.front().second;
                q.pop();
                if (root->left) q.push({root->left, end * 2});
                if (root->right) q.push({root->right, end * 2 + 1});
            }
            res = max(res, end - start + 1);
        }
        return res;
    }
};

// overflow in only one test case, overflow even with long long (above is the same)
// class Solution {
// public:
//     int widthOfBinaryTree(TreeNode* root) {
//         vector<int> start;
//         int res = -1;
//         dfs(root, start, 0, 1, res);
//         return res;
//     }
    
//     void dfs(TreeNode* root, vector<int>& start, int depth, int index, int& res) {
//         if (!root) return;
//         if (depth == start.size()) start.push_back(index);
//         res = max(res, index - start[depth] + 1);
//         dfs(root->left, start, depth + 1, index * 2, res);
//         dfs(root->right, start, depth + 1, index * 2 + 1, res);
//     }
// };