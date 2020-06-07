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
//     ListNode* removeZeroSumSublists(ListNode* head) {
//         ListNode *dummy = new ListNode(0), *curr = dummy;
//         dummy->next = head;
//         unordered_map<int, ListNode*> m;
//         int prefix = 0;
//         while (curr) {
//             prefix += curr->val;
//             if (m.count(prefix)) {
//                 curr = m[prefix]->next;
//                 int p = prefix + curr->val;
//                 while (p != prefix) {
//                     m.erase(p);
//                     curr = curr->next;
//                     p += curr->val;
//                 }
//                 m[prefix]->next = curr->next;
//             } else {
//                 m[prefix] = curr;
//             }
//             curr = curr->next;
//         }
//         return dummy->next;
//     }
// };


class Solution {
public:
    ListNode* removeZeroSumSublists(ListNode* head) {
        ListNode *dummy = new ListNode(0);
        dummy->next = head;
        unordered_map<int, ListNode*> m;
        int prefix = 0;
        for (ListNode *curr = dummy; curr; curr = curr->next) {
            prefix += curr->val;
            m[prefix] = curr;
        }
        prefix = 0;
        for (ListNode *curr = dummy; curr; curr = curr->next) {
            prefix += curr->val;
            curr->next = m[prefix]->next;
        }
        return dummy->next;
    }
};