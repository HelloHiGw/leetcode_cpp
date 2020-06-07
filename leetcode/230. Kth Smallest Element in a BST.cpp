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
//     int kthSmallest(TreeNode* root, int k) {
//         return dfs(root, k);
//     }
    
//     int dfs(TreeNode* root, int& k) {
//         if (!root) return -1;
//         int val = dfs(root->left, k);
//         if (k == 0) return val;
//         if (--k == 0) return root->val;
//         return dfs(root->right, k);
//     }
// };

// this is designed for the follow up
// count is also traversal, it is less efficient than straight inorder traversal 
class Solution {
public:
    int kthSmallest(TreeNode* root, int k) {
        int leftCount = countNodes(root->left);
        if (leftCount >= k) {
            return kthSmallest(root->left, k);
        } else if (leftCount == k - 1) {
            return root->val;
        } else {
            return kthSmallest(root->right, k - leftCount - 1);
        }
    }
    
    int countNodes(TreeNode* root) {
        if (!root) return 0;
        return 1 + countNodes(root->left) + countNodes(root->right);
    }
};

// follow up
/**
 * Definition for a binary tree node.
 * struct Node {
 *     int val;
 *     int cnt;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), cnt(1), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    Node build(TreeNode* root) {
        if (!root) return nullptr;
        Node curr = new Node(root->val);
        curr->left = build(root->left);
        curr->right = build(root->right);
        if (curr->left) curr->cnt += curr->left->cnt;
        if (curr->right) curr->cnt += curr->right->cnt;
        return Node;
    }

    int kthSmallest(TreeNode* root, int k) {
        Node node = build(root);
        return kthSmallestNode(node, k);
    }

    int kthSmallestNode(Node* root, int k) {
        if (root->left) {
            int leftCount = root->left->cnt;
            if (leftCount >= k) {
                return kthSmallestNode(root->left, k);
            } else if (leftCount == k - 1) {
                return root->val;
            } else {
                return kthSmallestNode(root->right, k - leftCount - 1);
            }
        } else {
            if (k == 1) return root->val;
            return kthSmallest(root->right, k - 1);
        }
        
    }
};

// how about inserting and deleting Nodes ? how to change corresponding cnt ？


