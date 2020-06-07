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

// dummy->next is the first node of a level
// use pre = dummy to avoid the judgement of if (pre) pre->next = ... and find the first node of next level
// set dummy->next = nullptr before entering the next level or TLE for the last level
// it is ok to use firstOfLevel and pre, but need to find firstOfLevel manually and judge pre before assignment
class Solution {
public:
    Node* connect(Node* root) {
        Node *dummy = new Node(0), *curr = root, *pre = dummy;
        while (curr) {
            while (curr) {
                if (curr->left) {
                    pre->next = curr->left;
                    pre = pre->next; 
                }
                if (curr->right) {
                    pre->next = curr->right;
                    pre = pre->next;
                }
                curr = curr->next;
            }
            curr = dummy->next;
            pre = dummy;
            dummy->next = nullptr;
        }
        return root;
    }
};