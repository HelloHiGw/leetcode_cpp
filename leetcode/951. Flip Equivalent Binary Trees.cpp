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
//     bool flipEquiv(TreeNode* root1, TreeNode* root2) {
//         if (!root1 || !root2) return root1 == root2;
//         if (root1->val != root2->val) return false;
//         if (root1->left && root2->left && root1->left->val == root2->left->val || !root1->left && !root2->left) return flipEquiv(root1->left, root2->left) && flipEquiv(root1->right, root2->right);
//         return flipEquiv(root1->left, root2->right) && flipEquiv(root1->right, root2->left);
//     }
// };


// class Solution {
// public:
//     bool flipEquiv(TreeNode* root1, TreeNode* root2) {
//         stack<TreeNode*> st;
//         st.push(root1);
//         st.push(root2);
//         while (!st.empty()) {
//             root1 = st.top();
//             st.pop();
//             root2 = st.top();
//             st.pop();
//             if (!root1 && !root2) continue;
//             if (!root1 || !root2 || root1->val != root2->val) return false;
//             if (root1->left && root2->left && root1->left->val == root2->left->val || !root1->left && !root2->left) {
//                 st.push(root1->right);
//                 st.push(root2->right);
//                 st.push(root1->left);
//                 st.push(root2->left);
//             } else {
//                 st.push(root1->right);
//                 st.push(root2->left);
//                 st.push(root1->left);
//                 st.push(root2->right);
//             }
//         }
//         return true;
//     }
// };

// class Solution {
// public:
//     bool flipEquiv(TreeNode* root1, TreeNode* root2) {
//         stack<TreeNode*> st;
//         while (!st.empty() || root1 || root2) {
//             while (root1 || root2) {
//                 if (root1) cout << "root1 == " << root1->val << "   ";
//                 if (root2) cout << "root2 == " << root2->val << endl;
//                 if (!root1 && root2 || root1 && !root2 || root1->val != root2->val) return false;
//                 if (root1->left && root2->left && root1->left->val == root2->left->val || !root1->left && !root2->left) {
//                     st.push(root1);
//                     root1 = root1->left;
//                     st.push(root2);
//                     root2 = root2->left;
//                 } else {
//                     st.push(root1);
//                     root1 = root1->left;
//                     st.push(root2);
//                     root2 = root2->right;
//                 }
                
//             }
//             // wrong here, because you do not konw NLR or NRL above
//             // if NLR, root = root->right here; if NRL, root = root->left
//             root1 = st.top();
//             root1 = root1->right;
//             st.pop();
//             root2 = st.top();
//             root2 = root2->right;
//             st.pop();
//         }
//         return true;
//     }
// };

class Solution {
public:
    bool flipEquiv(TreeNode* root1, TreeNode* root2) {
        queue<TreeNode*> q;
        q.push(root1);
        q.push(root2);
        while (!q.empty()) {
            root1 = q.front();
            q.pop();
            root2 = q.front();
            q.pop();
            if (!root1 && !root2) continue;
            if (!root1 || !root2 || root1->val != root2->val) return false;
            if (root1->left && root2->left && root1->left->val == root2->left->val || !root1->left && !root2->left) {
                q.push(root1->left);
                q.push(root2->left);
                q.push(root1->right);
                q.push(root2->right);
            } else {
                q.push(root1->left);
                q.push(root2->right);
                q.push(root1->right);
                q.push(root2->left);
            }
        }
        return true;
    }
};