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
//     TreeNode* bstFromPreorder(vector<int>& preorder) {
//         return buildBST(preorder, 0, preorder.size() - 1);
//     }
    
//     TreeNode* buildBST(vector<int>& preorder, int start, int end) {
//         if (start > end) return nullptr;
//         TreeNode* root = new TreeNode(preorder[start]);
//         int i = -1;
//         for (i = start + 1; i <= end; ++i) {
//             if (preorder[i] > preorder[start]) break;
//         }
//         root->left = buildBST(preorder, start + 1, i - 1);
//         root->right = buildBST(preorder, i, end);
//         return root;
//     }
// };

class Solution {
public:
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        int index = 0;
        return buildBST(preorder, index, nullptr); // use TreeNode* instead of INT_MAX
    }
    
    TreeNode* buildBST(vector<int>& preorder, int& index, TreeNode* bound) {
        if (index == preorder.size() || bound && preorder[index] > bound->val) return nullptr;
        TreeNode* root = new TreeNode(preorder[index++]);
        root->left = buildBST(preorder, index, root);
        root->right = buildBST(preorder, index, bound);
        return root;
    }
};