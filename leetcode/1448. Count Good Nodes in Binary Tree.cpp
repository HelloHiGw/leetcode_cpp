/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
// class Solution {
// public:
//     int goodNodes(TreeNode* root) {
//         return dfs(root, INT_MIN);
//     }
    
// private:
//     int dfs(TreeNode* root, int maxVal) {
//         if (!root) return 0;
//         int curr = root->val >= maxVal;
//         maxVal = max(maxVal, root->val);
//         return curr + dfs(root->left, maxVal) + dfs(root->right, maxVal);
//     }
// };

class Solution {
public:
    int goodNodes(TreeNode* root, int maxVal = INT_MIN) {
        if (!root) return 0;
        return (root->val >= maxVal) + goodNodes(root->left, max(maxVal, root->val)) + goodNodes(root->right, max(maxVal, root->val));
    }
};