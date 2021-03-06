/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/
// class Solution {
// public:
//     vector<vector<int>> levelOrder(Node* root) {
//         vector<vector<int>> res;
//         if (!root) return res;
//         queue<Node*> q;
//         q.push(root);
//         while (!q.empty()) {
//             vector<int> level;
//             for (int i = q.size(); i > 0; --i) {
//                 root = q.front();
//                 q.pop();
//                 level.push_back(root->val);
//                 for (Node* child : root->children) {
//                     q.push(child);
//                 }
//             }
//             res.push_back(level);
//         }
//         return res;
//     }
// };

class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
        vector<vector<int>> res;
        dfs(root, 0, res);
        return res;
    }
    
    void dfs(Node* root, int depth, vector<vector<int>>& res) {
        if (!root) return;
        if (depth == res.size()) res.push_back({});
        res[depth].push_back(root->val);
        for (Node* child : root->children) {
            dfs(child, depth + 1, res);
        }
    }
};