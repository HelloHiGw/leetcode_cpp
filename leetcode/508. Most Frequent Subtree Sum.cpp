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
    vector<int> findFrequentTreeSum(TreeNode* root) {
        unordered_map<int, int> m;
        int maxFreq = -1;
        dfs(root, m, maxFreq);
        vector<int> res;
        for (auto& it : m) {
            if (it.second == maxFreq) res.push_back(it.first);
        }
        return res;
    }
    
    int dfs(TreeNode* root, unordered_map<int, int>& m, int& maxFreq) {
        if (!root) return 0;
        int leftSum = dfs(root->left, m, maxFreq);
        int rightSum = dfs(root->right, m, maxFreq);
        int sum = leftSum + rightSum + root->val;
        ++m[sum];
        maxFreq = max(maxFreq, m[sum]);
        return sum;
    }
};