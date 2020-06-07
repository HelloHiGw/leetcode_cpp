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
//     vector<int> distanceK(TreeNode* root, TreeNode* target, int K) {
//         unordered_map<TreeNode*, TreeNode*> parent;
//         findParent(root, parent, nullptr);
//         unordered_set<TreeNode*> visited;
//         vector<int> res;
//         dfs(target, K, parent, visited, res);
//         return res;
//     }
    
//     void findParent(TreeNode* root, unordered_map<TreeNode*, TreeNode*>& parent, TreeNode* par) {
//         if (!root) return;
//         parent[root] = par;
//         findParent(root->left, parent, root);
//         findParent(root->right, parent, root);
//     }
    
//     void dfs(TreeNode* root, int K, unordered_map<TreeNode*, TreeNode*>& parent, unordered_set<TreeNode*>& visited, vector<int>& res) {
//         if (!root) return;
//         if (visited.find(root) != visited.end()) return;
//         visited.insert(root);
//         if (K == 0) {
//             res.push_back(root->val);
//             return;
//         }
//         dfs(root->left, K - 1, parent, visited, res);
//         dfs(root->right, K - 1, parent, visited, res);
//         dfs(parent[root], K - 1, parent, visited, res);
//     }
// };


// class Solution {
// public:
//     vector<int> distanceK(TreeNode* root, TreeNode* target, int K) {
//         unordered_map<TreeNode*, vector<TreeNode*>> m;
//         constructGraph(root, m, nullptr);
//         unordered_set<TreeNode*> visited;
//         vector<int> res;
//         queue<TreeNode*> q;
//         q.push(target);
//         visited.insert(target);
//         while (!q.empty()) {
//             if (K == 0) {
//                 for (int i = q.size(); i > 0; --i) {
//                     res.push_back(q.front()->val);
//                     q.pop();
//                 }
//                 break;
//             }
//             for (int i = q.size(); i > 0; --i) {
//                 TreeNode* node = q.front();
//                 q.pop();
//                 for (TreeNode* t : m[node]) {
//                     if (visited.find(t) == visited.end()) {
//                         q.push(t);
//                         visited.insert(t);
//                     }
//                 }
//             }
//             --K;
//         }
//         return res;
//     }
    
//     void constructGraph(TreeNode* root, unordered_map<TreeNode*, vector<TreeNode*>>& m, TreeNode* pre) {
//         if (!root) return;
//         if (pre) {
//             m[pre].push_back(root);
//             m[root].push_back(pre);
//         }
//         constructGraph(root->left, m, root);
//         constructGraph(root->right, m, root);
//     }
// };


// class Solution {
// public:
//     vector<int> distanceK(TreeNode* root, TreeNode* target, int K) {
//         unordered_map<TreeNode*, int> m;  // key: path node from root to target, val: dist(node, target)
//         findPath(root, target, m);
//         vector<int> res;
//         dfs(root, K, 0, m, res);
//         return res;
//     }
    
//     void findPath(TreeNode* root, TreeNode* target, unordered_map<TreeNode*, int>& m) {
//         if (!root) return;
//         if (root == target) {
//             m[root] = 0;
//             return;
//         }
//         findPath(root->left, target, m);
//         if (m.find(root->left) != m.end()) {
//             m[root] = m[root->left] + 1;
//             return;  // prune
//         }
//         findPath(root->right, target, m);
//         if (m.find(root->right) != m.end()) m[root] = m[root->right] + 1;
//     }
    
//     void dfs(TreeNode* root, int K, int dist, unordered_map<TreeNode*, int>& m, vector<int>& res) {
//         if (!root) return;
//         if (m.find(root) != m.end()) dist = m[root];
//         if (dist == K) {
//             res.push_back(root->val);
//         }
//         dfs(root->left, K, dist + 1, m, res);
//         dfs(root->right, K, dist + 1, m, res);
//     }
// };

// solution3 without map
class Solution {
public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int K) {
        vector<int> res;
        if (K == 0) {
            res.push_back(target->val);
            return res;
        }
        dfs(root, target, K, 0, res);
        return res;
    }
    
    // prune by returning 0
    int dfs(TreeNode* root, TreeNode* target, int K, int dist, vector<int>& res) {
        if (!root) return 0;  
        if (dist == K) {  // node in the subtree of target with dist == K
            res.push_back(root->val);
            return 0;  
        }
        int left = 0, right = 0;
        if (root == target || dist > 0) {  // root = target || dist > 0 : dfs the node in the subtree of target
            left = dfs(root->left, target, K, dist + 1, res);
            right = dfs(root->right, target, K, dist + 1, res);
        } else {  // find target
            left = dfs(root->left, target, K, dist, res);
            right = dfs(root->right, target, K, dist, res);
        }
        if (left == K || right == K) {  // target in the substree of curr and dist(curr, target) == k
            res.push_back(root->val);
            return 0;
        }
        if (root == target) {
            return 1;  // return > 0 denotes the dist from target to curr->parent
        }
        if (left > 0) {  // target in the leftSubtree, dfs root->right using dist = left + 1 
            dfs(root->right, target, K, left + 1, res);
            return left + 1;  // dist++
        }
        if (right > 0) {
            dfs(root->left, target, K, right + 1, res);
            return right + 1;
        }
        return 0;  // not found
    }
};