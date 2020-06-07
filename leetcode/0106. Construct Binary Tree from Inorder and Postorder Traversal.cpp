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
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        unordered_map<int, int> m;
        for (int i = 0; i < inorder.size(); ++i) {
            m[inorder[i]] = i;
        }
        return constructTree(inorder, postorder, 0, inorder.size() - 1, 0, postorder.size() - 1, m);
    }
    
    TreeNode* constructTree(vector<int>& inorder, vector<int>& postorder, int inStart, int inEnd, int postStart, int postEnd, unordered_map<int, int>& m) {
        if (inStart > inEnd) return NULL;
        int rootIndex = m[postorder[postEnd]];
        TreeNode* root = new TreeNode(inorder[rootIndex]);
        int leftNum = rootIndex - inStart;
        root->left = constructTree(inorder, postorder, inStart, rootIndex - 1, postStart, postStart + leftNum - 1, m);
        root->right = constructTree(inorder, postorder, rootIndex + 1, inEnd, postStart + leftNum, postEnd - 1, m);
        return root;
    }
};