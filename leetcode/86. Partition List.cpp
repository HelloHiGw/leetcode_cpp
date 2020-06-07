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
    ListNode* partition(ListNode* head, int x) {
        ListNode *lessHead = new ListNode(-1), *lessTail = lessHead;
        ListNode *greaterHead = new ListNode(-1), *greaterTail = greaterHead;
        while (head) {
            ListNode *t = head->next;
            head->next = nullptr;
            if (head->val < x) {
                lessTail->next = head;
                lessTail = head;
            } else {
                greaterTail->next = head;
                greaterTail = head;
            }
            head = t;
        }
        lessTail->next = greaterHead->next;
        return lessHead->next;
    }
};