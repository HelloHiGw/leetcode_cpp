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
    ListNode* insertionSortList(ListNode* head) {
        ListNode *dummy = new ListNode(-1);
        while (head) {
            ListNode *next = head->next;
            ListNode *node = dummy;
            while (node->next && node->next->val < head->val) node = node->next;
            head->next = node->next;
            node->next = head;
            head = next;
        }
        return dummy->next;
    }
};