/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/
// class Solution {
// public:
//     Node* connect(Node* root) {
//         if (!root) return nullptr;
//         queue<Node*> q;
//         q.push(root);
//         while (!q.empty()) {
//             Node* pre = nullptr;
//             for (int i = q.size(); i > 0; --i) {
//                 Node* p = q.front();
//                 q.pop();
//                 if (pre) pre->next = p;
//                 pre = p;
//                 if (p->left) q.push(p->left);
//                 if (p->right) q.push(p->right);
//             }
//         }
//         return root;
//     }
// };

class Solution {
public:
    Node* connect(Node* root) {
        if (!root) return nullptr;
        Node *firstOfLevel = root, *curr = root;
        while (curr->left) {
            while (curr) {
                curr->left->next = curr->right;
                if (curr->next) curr->right->next = curr->next->left;
                curr = curr->next;
            }
            firstOfLevel = firstOfLevel->left;
            curr = firstOfLevel;
        }
        return root;
    }
};