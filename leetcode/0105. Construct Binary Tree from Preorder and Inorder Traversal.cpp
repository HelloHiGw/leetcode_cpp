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
//     TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
//         return constructTree(preorder, inorder, 0, preorder.size() - 1, 0, inorder.size() - 1);
//     }
    
//     TreeNode* constructTree(vector<int>& preorder, vector<int>& inorder, int preStart, int preEnd, int inStart, int inEnd) {
//         if (preStart > preEnd) return NULL;
//         int rootIndex = -1;
//         for (rootIndex = inStart; rootIndex <= inEnd; ++rootIndex) {
//             if (inorder[rootIndex] == preorder[preStart]) break;
//         }
//         TreeNode* root = new TreeNode(inorder[rootIndex]);
//         int leftNum = rootIndex - inStart;
//         root->left = constructTree(preorder, inorder, preStart + 1, preStart + leftNum, inStart, rootIndex - 1);
//         root->right = constructTree(preorder, inorder, preStart + leftNum + 1, preEnd, rootIndex + 1, inEnd);
//         return root;
//     }
// };

class Solution {
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        unordered_map<int, int> m;
        for (int i = 0; i < inorder.size(); ++i) {
            m[inorder[i]] = i;
        }
        return constructTree(preorder, inorder, 0, preorder.size() - 1, 0, inorder.size() - 1, m);
    }
    
    TreeNode* constructTree(vector<int>& preorder, vector<int>& inorder, int preStart, int preEnd, int inStart, int inEnd, unordered_map<int, int>& m) {
        if (preStart > preEnd) return NULL;
        int rootIndex = m[preorder[preStart]];  // preorder[preStart] != preorder.front()
        TreeNode* root = new TreeNode(inorder[rootIndex]);
        int leftNum = rootIndex - inStart;
        root->left = constructTree(preorder, inorder, preStart + 1, preStart + leftNum, inStart, rootIndex - 1, m);
        root->right = constructTree(preorder, inorder, preStart + leftNum + 1, preEnd, rootIndex + 1, inEnd, m);
        return root;
    }
};