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
//     vector<vector<string>> printTree(TreeNode* root) {
//         int h = getHeight(root);
//         int w = pow(2, h) - 1;
//         vector<vector<string>> res(h, vector<string>(w));
//         dfs(root, res, 0, 0, w - 1);
//         return res;
//     }
    
//     int getHeight(TreeNode* root) {
//         if (!root) return 0;
//         return max(getHeight(root->left), getHeight(root->right)) + 1;
//     }
    
//     void dfs(TreeNode* root, vector<vector<string>>& res, int depth, int start, int end) {
//         if (!root) return;
//         int mid = (start + end) / 2;
//         res[depth][mid] = to_string(root->val);
//         dfs(root->left, res, depth + 1, start, mid - 1);
//         dfs(root->right, res, depth + 1, mid + 1, end);
//     }
// };

class Solution {
public:
    vector<vector<string>> printTree(TreeNode* root) {
        int h = getHeight(root);
        int w = pow(2, h) - 1;
        vector<vector<string>> res(h, vector<string>(w));
        if (!root) return res;
        queue<TreeNode*> q;
        queue<pair<int, int>> index;
        q.push(root);
        index.push({0, w - 1});
        int height = 0;
        while (!q.empty()) {
            for (int i = q.size(); i > 0; --i) {
                root = q.front();
                q.pop();
                pair<int, int> idx = index.front();
                index.pop();
                int mid = (idx.first + idx.second) / 2;
                res[height][mid] = to_string(root->val);
                if (root->left) {
                    q.push(root->left);
                    index.push({idx.first, mid - 1});
                }
                if (root->right) {
                    q.push(root->right);
                    index.push({mid + 1, idx.second});
                }
            }
            ++height;
        }
        return res;
    }
    
    int getHeight(TreeNode* root) {
        if (!root) return 0;
        return max(getHeight(root->left), getHeight(root->right)) + 1;
    }
};