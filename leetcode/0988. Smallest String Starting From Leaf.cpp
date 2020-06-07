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
    string smallestFromLeaf(TreeNode* root) {
        string res;
        dfs(root, "", res);
        return res;
    }
    
    void dfs(TreeNode* root, string s, string& res) {
        if (!root) return;
        s += char(root->val + 'a');
        if (!root->left && !root->right) {
            reverse(s.begin(), s.end());
            if (res.empty()) {
                res = s;
            } else {
                res = min(res, s);
            }
            return;
        }
        dfs(root->left, s, res);
        dfs(root->right, s, res);
    }
};

// wrong
// https://leetcode.com/problems/smallest-string-starting-from-leaf/discuss/244205/Divide-and-conquer-technique-doesn't-work-for-this-problem
// class Solution {
// public:
//     string smallestFromLeaf(TreeNode* root) {
//         if (!root) return "";
//         string s = string(1, 'a' + root->val);
//         if (!root->left && !root->right) return s;
//         string left = smallestFromLeaf(root->left);
//         string right = smallestFromLeaf(root->right);
//         if (left == "") return right + s;
//         if (right == "") return left + s;
//         return min(left + s, right + s);
//     }
// };