/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
// class Solution {
// public:
//     ListNode* deleteDuplicates(ListNode* head) {
//         ListNode *dummy = new ListNode(-1), *tail = dummy, *curr = head;
//         dummy->next = head;
//         while (curr) {
//             ListNode *node = curr->next;
//             while (node && node->val == curr->val) node = node->next;
//             if (node == curr->next) {
//                 tail->next = curr;
//                 tail = curr;
//             }
//             curr = node;
//         }
//         tail->next = nullptr;
//         return dummy->next;
//     }
// };


// class Solution {
// public:
//     ListNode* deleteDuplicates(ListNode* head) {
//         ListNode *dummy = new ListNode(-1), *tail = dummy, *curr = head;
//         dummy->next = head;
//         while (curr) {
//             while (curr->next && curr->next->val == curr->val) curr = curr->next;
//             if (tail->next == curr) {
//                 tail = tail->next;
//             } else {
//                 tail->next = curr->next;
//             }
//             curr = curr->next;
//         }
//         return dummy->next;
//     }
// };

class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if (!head || !head->next) return head;
        if (head->next->val == head->val) {
            while (head->next && head->next->val == head->val) head = head->next;
            return deleteDuplicates(head->next);
        } else {
            head->next = deleteDuplicates(head->next);
            return head;
        }
    }
};