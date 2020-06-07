/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *dummy = new ListNode(-1), *tail = dummy;
        int carry = 0;
        while (l1 || l2 || carry) {
            int d1 = l1 ? l1->val : 0;
            int d2 = l2 ? l2->val : 0;
            if (l1) l1 = l1->next;
            if (l2) l2 = l2->next;
            int temp = d1 + d2 + carry;
            carry = temp / 10;
            ListNode *node = new ListNode(temp % 10);
            tail->next = node;
            tail = node;
        }
        return dummy->next;
    }
};