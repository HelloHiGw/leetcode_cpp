/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
// TLE
// class Solution {
// public:
//     vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
//         unordered_map<TreeNode*, int> m;
//         vector<TreeNode*> res;
//         dfs(root, m, res);
//         return res;
//     }
    
//     bool isSameTree(TreeNode* p, TreeNode* q) {
//         if (!p || !q) return p == q;
//         if (p->val != q->val) return false;
//         return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
//     }
    
//     void dfs(TreeNode* root, unordered_map<TreeNode*, int>& m, vector<TreeNode*>& res) {
//         if (!root) return;
//         bool flag = false;
//         for (auto& it : m) {
//             if (isSameTree(root, it.first)) {
//                 if (it.second == 1) res.push_back(root);
//                 ++it.second;
//                 flag = true;
//                 break;
//             }
//         }
//         if (!flag) m[root] = 1;
//         dfs(root->left, m, res);
//         dfs(root->right, m, res);
//     }
// };

class Solution {
public:
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        unordered_map<string, int> m;
        vector<TreeNode*> res;
        dfs(root, m, res);
        return res;
    }

    string dfs(TreeNode* root, unordered_map<string, int>& m, vector<TreeNode*>& res) {
        if (!root) return "#";
        string left = dfs(root->left, m, res);
        string right = dfs(root->right, m, res);
        string curr = to_string(root->val) + "," + left + "," + right;
        if (m[curr] == 1) {
            res.push_back(root);
        }
        ++m[curr];
        return curr;
    }
};