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
//     ListNode* swapPairs(ListNode* head) {
//         ListNode *dummy = new ListNode(-1), *curr = dummy;
//         dummy->next = head;
//         while (curr->next && curr->next->next) {
//             ListNode *t = curr->next;
//             curr->next = t->next;
//             t->next = curr->next->next;
//             curr->next->next = t;
//             curr = t;
//         }
//         return dummy->next;
//     }
// };


class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        if (!head || !head->next) return head;
        ListNode *nxt = head->next;
        head->next = swapPairs(nxt->next);
        nxt->next = head;
        return nxt;
    }
};