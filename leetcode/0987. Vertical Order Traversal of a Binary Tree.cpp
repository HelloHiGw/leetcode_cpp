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
//     vector<vector<int>> verticalTraversal(TreeNode* root) {
//         unordered_map<int, unordered_map<int, set<int>>> m;
//         fillMap(root, 0, 0, m);
//         vector<vector<int>> res;
//         for (int x = -999; x < 1000; ++x) {  // or you can find minX, maxX, maxY in fillMap
//             if (m.find(x) != m.end()) {
//                 vector<int> v;
//                 for (int y = 0; y < 1000; ++y) {
//                     if (m[x].find(y) != m[x].end()) {
//                         v.insert(v.end(), m[x][y].begin(), m[x][y].end());
//                     }
//                 }
//                 res.push_back(v);
//             }
//         }
//         return res;
//     }
    
//     void fillMap(TreeNode* root, int x, int y, unordered_map<int, unordered_map<int, set<int>>>& m) {
//         if (!root) return;
//         m[x][y].insert(root->val);
//         fillMap(root->left, x - 1, y + 1, m);
//         fillMap(root->right, x + 1, y + 1, m);
//     }
// };

// class Solution {
// public:
//     vector<vector<int>> verticalTraversal(TreeNode* root) {
//         map<int, map<int, set<int>>> m;
//         fillMap(root, 0, 0, m);
//         vector<vector<int>> res;
//         for (auto itX : m) {
//             vector<int> v;
//             for (auto itY : itX.second) {
//                 v.insert(v.end(), itY.second.begin(), itY.second.end());
//             }
//             res.push_back(v);
//         }
//         return res;
//     }
    
//     void fillMap(TreeNode* root, int x, int y, map<int, map<int, set<int>>>& m) {
//         if (!root) return;
//         m[x][y].insert(root->val);
//         fillMap(root->left, x - 1, y + 1, m);
//         fillMap(root->right, x + 1, y + 1, m);
//     }
// };


class Solution {
    
struct Node{
    TreeNode* n;
    int x, y;
};
    
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        unordered_map<int, unordered_map<int, set<int>>> m;
        queue<Node*> q;
        q.push(new Node{root, 0, 0});
        while (!q.empty()) {
            for (int i = q.size(); i > 0; --i) {
                Node* node = q.front();
                q.pop();
                m[node->x][node->y].insert(node->n->val);
                if (node->n->left) {
                    q.push(new Node{node->n->left, node->x - 1, node->y + 1});
                }
                if (node->n->right) {
                    q.push(new Node{node->n->right, node->x + 1, node->y + 1});
                }
            }
        }
        vector<vector<int>> res;
        for (int x = -999; x < 1000; ++x) {  // or you can find minX, maxX, maxY in fillMap
            if (m.find(x) != m.end()) {
                vector<int> v;
                for (int y = 0; y < 1000; ++y) {
                    if (m[x].find(y) != m[x].end()) {
                        v.insert(v.end(), m[x][y].begin(), m[x][y].end());
                    }
                }
                res.push_back(v);
            }
        }
        return res;
    }
};

