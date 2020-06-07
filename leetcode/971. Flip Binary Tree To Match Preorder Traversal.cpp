/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
// test case
// [1,2,4,3,null,5,6]
// [1,2,7,4,6,5]
// class Solution {
// public:
//     vector<int> flipMatchVoyage(TreeNode* root, vector<int>& voyage) {
//         vector<int> res;
//         int count = 0;
//         dfs(root, voyage, count, res);
//         return res;
//     }
    
//     void dfs(TreeNode* root, vector<int>& voyage, int& count, vector<int>& res) {
//         if (!root) return;
//         if (res.size() == 1 && res[0] == -1) return;  // prune
//         ++count;
//         if (voyage[count - 1] != root->val) {
//             res.clear();
//             res.push_back(-1);
//             return;
//         }
//         if (root->left && root->left->val != voyage[count]) {
//             res.push_back(root->val);
//             dfs(root->right, voyage, count, res);
//             dfs(root->left, voyage, count, res);
//         } else {
//             dfs(root->left, voyage, count, res);
//             dfs(root->right, voyage, count, res);
//         }
//     }
// };

// class Solution {
// public:
//     vector<int> flipMatchVoyage(TreeNode* root, vector<int>& voyage) {
//         vector<int> res;
//         int count = 0;
//         return dfs(root, voyage, count, res) ? res : vector<int>{-1};
//     }
    
//     bool dfs(TreeNode* root, vector<int>& voyage, int& count, vector<int>& res) {
//         if (!root) return true;
//         ++count;
//         if (voyage[count - 1] != root->val) return false;
//         if (root->left && root->left->val != voyage[count]) {
//             res.push_back(root->val);
//             return dfs(root->right, voyage, count, res) &&  dfs(root->left, voyage, count, res);
//         } else {
//             return dfs(root->left, voyage, count, res) && dfs(root->right, voyage, count, res);
//         }
//     }
// };

class Solution {
public:
    vector<int> flipMatchVoyage(TreeNode* root, vector<int>& voyage) {
        if (!root) return {};
        vector<int> res;
        stack<TreeNode*> st;
        st.push(root);
        int count = 0;
        while (!st.empty()) {
            root = st.top();
            st.pop();
            if (!root) continue;
            if (root->val != voyage[count++]) return vector<int>{-1};
            if (root->left && root->left->val != voyage[count]) {
                res.push_back(root->val);
                st.push(root->left);
                st.push(root->right);
            } else {
                st.push(root->right);
                st.push(root->left);
            }
        }
        return res;
    }
};