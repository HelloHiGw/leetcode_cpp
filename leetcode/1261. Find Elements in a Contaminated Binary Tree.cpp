/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class FindElements {
public:
    // constructor
    FindElements(TreeNode* root) {
        dfs(root, 0);
    }
    
    bool find(int target) {
        return st.find(target) != st.end();
    }
    
    void dfs(TreeNode* root, int x) {
        if (!root) return;
        root->val = x;
        st.insert(x);
        dfs(root->left, 2 * x + 1);
        dfs(root->right, 2 * x + 2);
    }
    
private:
    unordered_set<int> st;
};

/**
 * Your FindElements object will be instantiated and called as such:
 * FindElements* obj = new FindElements(root);
 * bool param_1 = obj->find(target);
 */