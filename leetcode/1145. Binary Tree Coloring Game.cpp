/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
// ignore the statement: Then, the players take turns starting with the first player.
// p1 red,  p2 blue, color won't change
class Solution {
public:
    bool btreeGameWinningMove(TreeNode* root, int n, int x) {
        int leftCount = 0, rightCount = 0;
        dfs(root, x, leftCount, rightCount);
        return max(max(leftCount, rightCount), n - leftCount - rightCount - 1) > n / 2;
    }
    
    int dfs(TreeNode* root, int x, int& leftCount, int& rightCount) {
        if (!root) return 0;
        int left = dfs(root->left, x, leftCount, rightCount), right = dfs(root->right, x, leftCount, rightCount);
        if (root->val == x) {
            leftCount = left;
            rightCount = right;
        }
        return left + right + 1;
    }
};