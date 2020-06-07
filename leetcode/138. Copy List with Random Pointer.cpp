/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

// class Solution {
// public:
//     Node* copyRandomList(Node* head) {
//         unordered_map<Node*, Node*> m;
//         Node *curr = head;
//         Node *dummy = new Node(-1), *tail = dummy;
//         while (curr) {
//             Node *node = new Node(curr->val);
//             m[curr] = node;  // m[oriNode] = corresponding new node
//             tail->next = node;
//             tail = node;
//             curr = curr->next;
//         }
//         curr = head;
//         Node *node = dummy->next;
//         while (curr) {
//             node->random = m[curr->random];
//             node = node->next;
//             curr = curr->next;
//         }
//         return dummy->next;
//     }
// };

class Solution {
public:
    Node* copyRandomList(Node* head) {
        Node *curr = head;
        // First round: make copy of each node,
        // and link them together side-by-side in a single list.
        while (curr) {
            Node *node = new Node(curr->val);
            Node *next = curr->next;
            curr->next = node;
            node->next = next;
            curr = next;
        }
         // Second round: assign random pointers for the copy nodes.
        curr = head;
        while (curr) {
            if (curr->random) curr->next->random = curr->random->next;
            curr = curr->next->next;
        }
        // Third round: restore the original list, and extract the copy list.
        Node *dummy = new Node(-1), *tail = dummy;
        curr = head;
        while (curr) {
            Node *next = curr->next->next;
            tail->next = curr->next;
            tail = tail->next;
            curr->next = next;
            curr = next;
        }
        return dummy->next;
    }
};