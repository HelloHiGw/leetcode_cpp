/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};
*/
// O(n) and O(depth, number of branchs)
// class Solution {
// public:
//     Node* flatten(Node* head) {
//         flattenTail(head);
//         return head;
//     }

// private:
//     Node* flattenTail(Node* head) {  // flatten and return tail
//         if (!head) return nullptr;
//         Node *curr = head, *t = nullptr;
//         while (curr) {
//             if (curr->child) {
//                 Node *next = curr->next;
//                 Node *tail = flattenTail(curr->child);
//                 curr->next = curr->child;  // curr->next is child this situation, do not need return by flatten
//                 curr->child->prev = curr;
//                 curr->child = nullptr;
//                 tail->next = next;
//                 if (next) next->prev = tail;  // in case next = nullptr
//                 curr = tail;
//             }
//             t = curr;
//             curr = curr->next;
//         }
//         return t;
//     }
// };


// O(2N) worst case (no next but child) and O(1)
class Solution {
public:
    Node* flatten(Node* head) {
        for (Node* curr = head; curr; curr = curr->next) {
            if (curr->child) {
                Node *next = curr->next;
                curr->next = curr->child;
                curr->child->prev = curr;
                curr->child = nullptr;
                Node *t = curr->next;
                while (t->next) t = t->next;  // O(2N)
                t->next = next;
                if (next) next->prev = t;
            }
        }
        return head;
    }
};