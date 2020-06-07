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
    void reorderList(ListNode* head) {
        ListNode *dummy = new ListNode(-1), *slow = dummy, *fast = dummy;
        dummy->next = head;
        while (fast && fast->next) {
            fast = fast->next->next;
            slow = slow->next;
        }
        ListNode *head2 = slow->next;
        slow->next = nullptr;
        head2 = reverse(head2);
        ListNode *tail = dummy;
        while (head2) {
            tail->next = head;
            tail = tail->next;
            head = head->next;
            tail->next = head2;
            tail = tail->next;
            head2 = head2->next;
        }
        if (head) {
            tail->next = head;
        }
        head = dummy->next;
    }
    
    ListNode *reverse(ListNode *head) {
        ListNode *newHead = nullptr;
        while (head) {
            ListNode *next = head->next;
            head->next = newHead;
            newHead = head;
            head = next;
        }
        return newHead;
    }
};