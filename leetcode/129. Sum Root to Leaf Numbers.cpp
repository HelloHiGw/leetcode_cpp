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
//     int sumNumbers(TreeNode* root) {
//         return dfs(root, 0);
//     }
    
//     int dfs(TreeNode* root, int num) {
//         if (!root) return 0;
//         num = num * 10 + root->val;
//         if (!root->left && !root->right) return num;
//         return dfs(root->left, num) + dfs(root->right, num);
//     }
// };

class Solution {
public:
    int sumNumbers(TreeNode* root) {
        stack<TreeNode*> st;
        int num = 0, res = 0;
        TreeNode* pre = nullptr;
        while (!st.empty() || root) {
            while (root) {
                st.push(root);
                num = num * 10 + root->val;
                root = root->left;
            }
            root = st.top();
            if (!root->left && !root->right) res += num;
            if (root->right && root->right != pre) {
                root = root->right;
            } else {
                pre = root;
                root = nullptr;
                num /= 10;
                st.pop();
            }
        }
        return res;
    }
};