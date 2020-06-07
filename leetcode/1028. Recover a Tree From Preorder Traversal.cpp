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
    TreeNode* recoverFromPreorder(string S) {
        vector<TreeNode*> st;
        for (int i = 0, level = 0, val = 0; i < S.size();) {
            for (level = 0; i < S.size() && S[i] == '-'; ++i) {
                ++level;
            }
            for (val = 0; i < S.size() && S[i] != '-'; ++i) {
                val = val * 10 + (S[i] - '0');
            }
            TreeNode *root = new TreeNode(val);
            while (st.size() > level) st.pop_back();
            if (!st.empty()) {
                if (!st.back()->left) {
                    st.back()->left = root;
                } else {
                    st.back()->right = root;
                }
            }
            st.push_back(root);
        }
        return st[0];
    }
};

//the elements in the stack is the path from root to curr.