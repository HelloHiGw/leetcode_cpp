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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if (!root) return {};
        vector<vector<int>> res;
        queue<TreeNode*> q;
        q.push(root);
        bool left_to_right = true;
        while (!q.empty()) {
            int size = q.size();
            vector<int> v(size);
            for (int i = 0; i < size; ++i) {
                root = q.front();
                q.pop();
                int index = left_to_right ? i : (size - i - 1);
                v[index] = root->val;
                if (root->left) q.push(root->left);
                if (root->right) q.push(root->right);
            }
            left_to_right = !left_to_right;
            res.push_back(v);
        }
        return res;
    }
};