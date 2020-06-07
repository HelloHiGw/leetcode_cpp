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
//     vector<vector<int>> pathSum(TreeNode* root, int sum) {
//         vector<vector<int>> res;
//         vector<int> path;
//         dfs(root, sum, path, res);
//         return res;
//     }
    
//     void dfs(TreeNode* root, int sum, vector<int>& path, vector<vector<int>>& res) {
//         if (!root) return;
//         path.push_back(root->val);
//         if (!root->left && !root->right && sum == root->val) {
//             res.push_back(path);
//         }
//         dfs(root->left, sum - root->val, path, res);
//         dfs(root->right, sum - root->val, path, res);
//         path.pop_back();
//     }
// };

// https://www.cnblogs.com/grandyang/p/4042156.html
// 由于中序遍历的特点，遍历到当前结点的时候，是有两种情况的，有可能此时是从左子结点跳回来的，此时正要去右子结点，
// 则当前的结点值还是算在路径中的；也有可能当前是从右子结点跳回来的，并且此时要跳回上一个结点去，
// 此时就要减去当前结点值，因为其已经不属于路径中的结点了。
// 为了区分这两种情况，这里使用一个额外指针 pre 来指向前一个结点，
// 如果右子结点存在且不等于 pre，直接将指针移到右子结点，反之更新 pre 为 cur，
// cur 重置为空，val 减去当前结点，st 删掉最后一个结点
class Solution {
public:
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        vector<vector<int>> res;
        vector<TreeNode*> st;  // use vector to simulate stack for copying path convenience
        TreeNode* pre = nullptr;  // the pre node in poping stack sequence (a bit like postorder)
        int pathSum = 0;
        while (root || !st.empty()) {
            while (root) {
                st.push_back(root);
                pathSum += root->val;
                root = root->left;
            }
            root = st.back();  // need to record the path, do not pop_back() here
            if (!root->left && !root->right && pathSum == sum) {
                vector<int> v;
                for (TreeNode* node : st) {
                    v.push_back(node->val);
                }
                res.push_back(v);
            }
            if (root->right && root->right != pre) {  // need pre to avoid traversing the rightSubtree twice
                root = root->right;
            } else {
                pathSum -= root->val;
                pre = root;
                root = nullptr;
                st.pop_back();
            }
        }
        return res;
    }
};