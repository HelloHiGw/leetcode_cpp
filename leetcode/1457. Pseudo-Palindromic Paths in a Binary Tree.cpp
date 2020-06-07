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

/*
written by myself

Recursively iterate all paths from root to leaves,
count the occurrence of each digits in an hashset.

Whenever meet an element, toggle it in the set:
If set contains it, remove it.
If set donesn't contain it, add it.

At the leaf node, check if the size of set <= 1.

Time O(N)
Space O(K + H)  
H:height of tree,  K different numbers, K = 10 this problem

also you can use unordered_map<int, int>
but the time is (N * K), because when you check pseudo-panlindrome, it is O(K)
*/
class Solution {
public:
    int pseudoPalindromicPaths (TreeNode* root) {
        unordered_set<int> st;
        return dfs(root, st);
    }
    
private:
    // you must use &, otherwise it will TLE
    int dfs(TreeNode* root, unordered_set<int>& st) {
        if (!root) return 0;

        if (st.count(root->val)) {
            st.erase(root->val);
        } else {
            st.insert(root->val);
        }
        
        int res = 0;
        if (!root->left && !root->right) {
            res = st.size() <= 1;
        } else {
            res = dfs(root->left, st) + dfs(root->right, st);
        }
        
        if (st.count(root->val)) {
            st.erase(root->val);
        } else {
            st.insert(root->val);
        }
        
        return res;
    }
};


/*
Recursively iterate all paths from root to leaves,
count the occurrence of each digits in an integer.

Use this integer as a bit mask.

Whenever meet an element,
toggle the corresponding bit using ^ operation. (amount to the above erase and insert)

At the leaf node,
check if the count has only one bit that is 1 or count == 0

We use lowbit to help count this.

Time O(N)
Space O(K + H)

*/
class Solution {
public:
    int pseudoPalindromicPaths (TreeNode* root) {
        return dfs(root, 0);
    }
    
private:
    int dfs(TreeNode* root, int count) {
        if (!root) return 0;
        count ^= 1 << (root->val - 1);
        
        if (!root->left && !root->right) {
            // count is 0 or there is at most one 1 in count
            // O(1)
            return (count & (count - 1)) == 0;
        }
        return dfs(root->left, count) + dfs(root->right, count);
    }
};