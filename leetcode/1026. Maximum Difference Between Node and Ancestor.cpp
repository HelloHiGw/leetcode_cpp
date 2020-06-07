/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
// down top
// class Solution {
// public:
//     int maxAncestorDiff(TreeNode* root) {
//         int res = 0;
//         dfs(root, res);
//         return res;
//     }
    
//     pair<int, int> dfs(TreeNode* root, int& res) {
//         if (!root) return {INT_MAX, INT_MIN};
//         if (!root->left && !root->right) {
//             return {root->val, root->val};
//         }
//         auto left = dfs(root->left, res);
//         auto right = dfs(root->right, res);
//         int minSubtreeVal = min(left.first, right.first);
//         int maxSubtreeVal = max(left.second, right.second);
//         int curr = max(abs(root->val - minSubtreeVal), abs(root->val - maxSubtreeVal));
//         res = max(res, curr);
//         return {min(minSubtreeVal, root->val), max(maxSubtreeVal, root->val)};
//     }
// };


// top down
class Solution {
public:
    int maxAncestorDiff(TreeNode* root) {
        return dfs(root, root->val, root->val);
    }
    
    int dfs(TreeNode* root, int mn, int mx) {
        if (!root) return mx - mn;
        mn = min(root->val, mn);
        mx = max(root->val, mx);
        return max(dfs(root->left, mn, mx), dfs(root->right, mn, mx));
    }
};