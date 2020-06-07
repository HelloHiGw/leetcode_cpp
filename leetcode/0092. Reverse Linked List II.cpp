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
//     ListNode* reverseBetween(ListNode* head, int m, int n) {
//         if (!head) return nullptr;
//         ListNode *dummy = new ListNode(-1), *curr = dummy;
//         dummy->next = head;
//         for (int i = 0; i < m - 1; ++i) curr = curr->next;
//         ListNode *node = curr->next, *reversedHead = nullptr, *tail = curr->next;
//         for (int i = 0; i < n - m + 1; ++i) {
//             ListNode *nxt = node->next;
//             node->next = reversedHead;
//             reversedHead = node;
//             node = nxt;
//         }
//         tail->next = node;
//         curr->next = reversedHead;
//         return dummy->next;
//     }
// };


class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        ListNode *dummy = new ListNode(-1), *pre = dummy;
        dummy->next = head;
        for (int i = 0; i < m - 1; ++i) pre = pre->next;
        ListNode *curr = pre->next;
        for (int i = 0; i < n - m; ++i) {
            ListNode *t = curr->next;
            curr->next = t->next;
            t->next = pre->next;
            pre->next = t;
        }
        return dummy->next;
    }
};