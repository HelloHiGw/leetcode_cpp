/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
// dp in tree (it is always bottom up)

/* 
optimal substructure:
if we want to rob maximum amount of money from current binary tree (rooted at root), 
we surely hope that we can do the same to its left and right subtrees.

let's define the function rob(root) which will return 
the maximum amount of money that we can rob for the binary tree rooted at root
*/
class Solution {
public:
    int rob(TreeNode* root) {
        if (!root) return 0;
        int notRobRoot = rob(root->left) + rob(root->right);
        int robRoot = root->val;
        if (root->left) {
            robRoot += rob(root->left->left) + rob(root->left->right);
        }
        if (root->right) {
            robRoot += rob(root->right->left) + rob(root->right->right);
        }
        return max(notRobRoot, robRoot);
    }
};


/*
"optimal substructure" + "overlapping of subproblems"
 we actually have a DP problem. A naive way to implement DP here is to 
 use a hash map to record the results for visited subtrees
*/
class Solution {
public:
    int rob(TreeNode* root) {
        unordered_map<TreeNode*, int> memo;
        return robSub(root, memo);
    }
    
private:
    int robSub(TreeNode* root, unordered_map<TreeNode*, int> &memo) {
        if (!root) return 0;
        if (memo.count(root)) return memo[root];
        int val = root->val;
        if (root->left) {
            val += robSub(root->left->left, memo) + robSub(root->left->right, memo);
        }
        if (root->right) {
            val += robSub(root->right->left, memo) + robSub(root->right->right, memo);
        }
        return memo[root] = max(val, robSub(root->left, memo) + robSub(root->right, memo));
    }
};

/*
for each tree root, there are two scenarios: it is robbed or is not. 
rob(root) does not distinguish between these two cases, 
so "information is lost as the recursion goes deeper and deeper", 
which results in repeated subproblems. (?)
*/
class Solution {
public:
    int rob(TreeNode* root) {
        auto p = robSub(root);
        return max(p.first, p.second);
    }
    
private:
    pair<int, int> robSub(TreeNode* root) {
        if (!root) return {0, 0};
        auto pLeft = robSub(root->left), pRight = robSub(root->right);
        int notRobRoot = max(pLeft.first, pLeft.second) + max(pRight.first, pRight.second);
        int robRoot = pLeft.first + pRight.first + root->val;
        return {notRobRoot, robRoot};
    }
};