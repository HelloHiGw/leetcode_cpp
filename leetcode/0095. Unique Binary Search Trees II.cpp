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
//     vector<TreeNode*> generateTrees(int n) {
//         if (n == 0) return {};
//         return genTrees(1, n);
//     }
    
//     vector<TreeNode*> genTrees(int low, int high) {
//         if (low > high) return {NULL};
//         vector<TreeNode*> res;
//         for (int r = low; r <= high; ++r) {
//             vector<TreeNode*> leftSubtree = genTrees(low, r - 1);
//             vector<TreeNode*> rightSubtree = genTrees(r + 1, high);
//             for (TreeNode* left : leftSubtree) {
//                 for (TreeNode* right : rightSubtree) {
//                     TreeNode* root = new TreeNode(r);
//                     root->left = left;
//                     root->right = right;
//                     res.push_back(root);
//                 }
//             }
//         }
//         return res;
//     }
// };


class Solution {
public:
    vector<TreeNode*> generateTrees(int n) {
        if (n == 0) return {};
        vector<vector<vector<TreeNode*>>> memo(n + 1,vector<vector<TreeNode*>>(n + 1));
        return genTrees(1, n, memo);
    }
    
    vector<TreeNode*> genTrees(int low, int high, vector<vector<vector<TreeNode*>>>& memo) {
        if (low > high) return {NULL};
        if (!memo[low][high].empty()) return memo[low][high];
        vector<TreeNode*> res;
        for (int r = low; r <= high; ++r) {
            vector<TreeNode*> leftSubtree = genTrees(low, r - 1, memo);
            vector<TreeNode*> rightSubtree = genTrees(r + 1, high, memo);
            for (TreeNode* left : leftSubtree) {
                for (TreeNode* right : rightSubtree) {
                    TreeNode* root = new TreeNode(r);
                    root->left = left;
                    root->right = right;
                    res.push_back(root);
                }
            }
        }
        return memo[low][high] = res;
    }
};