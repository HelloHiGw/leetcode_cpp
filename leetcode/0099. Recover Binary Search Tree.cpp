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
//     void recoverTree(TreeNode* root) {
//         vector<TreeNode*> v;
//         dfs(root, v);
//         vector<int> v2(v.size());
//         for (int i = 0; i < v.size(); ++i) {
//             v2[i] = v[i]->val;
//         }
//         sort(v2.begin(), v2.end());
//         for (int i = 0; i < v.size(); ++i) {
//             if (v[i]->val != v2[i]) v[i]->val = v2[i];
//         }
//     }
    
//     void dfs(TreeNode* root, vector<TreeNode*>& v) {
//         if (!root) return;
//         dfs(root->left, v);
//         v.push_back(root);
//         dfs(root->right, v);
//     }
// };

class Solution {
public:
    void recoverTree(TreeNode* root) {
        TreeNode *first = nullptr, *second = nullptr, *pre = nullptr;
        dfs(root, first, second, pre);
        swap(first->val, second->val);
    }
    
    void dfs(TreeNode* root, TreeNode*& first, TreeNode*& second, TreeNode*& pre) {
        if (!root) return;
        dfs(root->left, first, second, pre);
        if (!first && pre && pre->val >= root->val) first = pre;
        if (first && pre->val >= root->val) second = root;
        pre = root;
        dfs(root->right, first, second, pre);
    }
};

// 1 2 6 4 5 3 7 8
// use arrow diagiam to understand the first = pre and second = root