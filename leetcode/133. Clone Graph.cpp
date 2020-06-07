/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

// class Solution {
// public:
//     Node* cloneGraph(Node* node) {
//         if (!node) return nullptr;
//         unordered_map<int, Node*> m;
//         dfs(node, m);
//         return m[1];
//     }

// private:
//     void dfs(Node *node, unordered_map<int, Node*> &m) {
//         if (m.count(node->val) == 0) m[node->val] = new Node(node->val);
//         Node *curr = m[node->val];
//         for (Node *nei : node->neighbors) {
//             if (m.count(nei->val) == 0) {  // m.count == 0 denotes not visited
//                 dfs(nei, m);
//             }
//             curr->neighbors.push_back(m[nei->val]);
//         }     
//     }
// };



class Solution {
public:
    Node* cloneGraph(Node* node) {
        if (!node) return nullptr;
        unordered_map<int, Node*> m;
        queue<Node*> q;
        q.push(node);
        m[node->val] = new Node(node->val);
        while (!q.empty()) {
            node = q.front();
            q.pop();
            Node *newNode = m[node->val];
            for (Node *nei : node->neighbors) {
                if (m.count(nei->val) == 0) {
                    m[nei->val] = new Node(nei->val);
                    q.push(nei);  // m.count == 0 denotes not visited
                }
                newNode->neighbors.push_back(m[nei->val]);
            }
        }
        return m[1];
    }
};


// class Solution {
// public:
//     Node* cloneGraph(Node* node) {
//         if (!node) return nullptr;
//         unordered_map<int, Node*> m;
//         return clone(node, m);
//     }

// private:
//     Node* clone(Node *node, unordered_map<int, Node*> &m) {
//         if (m.count(node->val)) return m[node->val];
//         Node *newNode = new Node(node->val);
//         m[newNode->val] = newNode;
//         for (Node *nei : node->neighbors) {
//             newNode->neighbors.push_back(clone(nei, m));
//         }
//         return newNode; 
//     }
// };
