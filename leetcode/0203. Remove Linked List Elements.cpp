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
//     ListNode* removeElements(ListNode* head, int val) {
//         ListNode *dummy = new ListNode(-1), *curr = dummy;
//         dummy->next = head;
//         while (curr && curr->next) {
//             if (curr->next->val == val) {
//                 curr->next = curr->next->next;
//             } else {
//                 curr = curr->next;
//             }
//         }
//         return dummy->next;
//     }
// };


class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        if (!head) return nullptr;
        head->next = removeElements(head->next, val);
        if (head->val == val) return head->next;
        return head;
    }
};