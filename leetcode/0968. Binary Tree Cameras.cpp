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
    int minCameraCover(TreeNode* root) {
        int res = 0;
        return dfs(root, res) == 0 ? ++res : res;
    }
    
    int dfs(TreeNode *root, int &res) {
        if (!root) return 2;
        int left = dfs(root->left, res), right = dfs(root->right, res);
        if (left == 0 || right == 0) {
            ++res;
            return 1;
        } else if (left == 1 || right == 1) {
            return 2;
        } else {
            return 0;
        }
    }
};

/*
If we set a camera at its parent, the camera can cover the leaf, its parent and its sibling.
Return 0 if it's a leaf. (not monitored)
Return 1 if it's a parent of a leaf, with a camera on this node.
Return 2 if it's coverd, without a camera on this node. // 自食其力，不用管它

private int NOT_MONITORED = 0;
private int MONITORED_WITHCAM = 1;
private int MONITORED_NOCAM = 2;
*/