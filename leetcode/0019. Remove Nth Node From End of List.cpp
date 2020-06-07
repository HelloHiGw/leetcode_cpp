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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode *dummy = new ListNode(-1), *early = dummy, *late = dummy;
        dummy->next = head;
        for (int i = 0; i < n; ++i) early = early->next;
        while (early->next) {
            early = early->next;
            late = late->next;
        }
        ListNode *t = late->next;
        late->next = t->next;
        delete t;
        return dummy->next;
    }
};