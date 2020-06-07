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
//     bool isSameTree(TreeNode* p, TreeNode* q) {
//         if (!p || !q) return p == q;
//         if (p->val != q->val) return false;
//         return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
//     }
// };

// same (pre, in, post, level) traversal sequence do not mean same tree
// but put nullptr children into it, it is 
// class Solution {
// public:
//     bool isSameTree(TreeNode* p, TreeNode* q) {
//         if (!p || !q) return p == q;
//         stack<TreeNode*> st;
//         st.push(p);
//         st.push(q);
//         while (!st.empty()) {
//             p = st.top();
//             st.pop();
//             q = st.top();
//             st.pop();
//             if (!p && !q) continue;
//             if (!p || !q) return false;
//             if (p->val != q->val) return false;
//             st.push(p->right);
//             st.push(q->right);
//             st.push(p->left);
//             st.push(q->left);
//         }
//         return true;
//     }
// };


// class Solution {
// public:
//     bool isSameTree(TreeNode* p, TreeNode* q) {
//         stack<TreeNode*> st;
//         while (!st.empty() || p || q) {
//             while (p || q) {
//                 if (!p && q || !q && p || p->val != q->val) return false;
//                 st.push(p);
//                 p = p->left;
//                 st.push(q);
//                 q = q->left;
//             }
//             p = st.top();
//             p = p->right;
//             st.pop();
//             q = st.top();
//             q = q->right;
//             st.pop();
//         }
//         return true;
//     }
// };

class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        queue<TreeNode*> que;
        que.push(p);
        que.push(q);
        while (!que.empty()) {
            p = que.front();
            que.pop();
            q = que.front();
            que.pop();
            if (!p && !q) continue;
            if (!p || !q) return false;
            if (p->val != q->val) return false;
            que.push(p->left);
            que.push(q->left);
            que.push(p->right);
            que.push(q->right);
        }
        return true;
    }
};
