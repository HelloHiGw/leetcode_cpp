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
    vector<TreeNode*> allPossibleFBT(int N) {
        if (N % 2 == 0) return {};
        vector<vector<TreeNode*>> res(N + 1);
        res[0] = {nullptr};
        for (int i = 1; i <= N; i += 2) {
            vector<TreeNode*> v;
            for (int j = 1; j <= i; ++j) {
                vector<TreeNode*> leftSubtree = res[j - 1], rightSubtree = res[i - j];
                for (TreeNode* left : leftSubtree) {
                    for (TreeNode* right : rightSubtree) {
                        TreeNode* root = new TreeNode(0);
                        root->left = left;
                        root->right = right;
                        v.push_back(root);
                    }
                }
            }
            res[i] = v;
        }
        return res[N];
    }
};