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
    ListNode* rotateRight(ListNode* head, int k) {
        if (!head) return nullptr;
        ListNode *tail = nullptr;
        int len = getLength(head, tail);
        k %= len;
        if (k == 0) return head;
        ListNode *curr = head;
        for (int i = 0; i < len - k - 1; ++i) {
            curr = curr->next;
        }
        ListNode *t = curr->next;
        curr->next = nullptr;
        tail->next = head;
        return t;
    }
    
    int getLength(ListNode* head, ListNode *&tail) {
        int cnt = 0;
        while (head) {
            ++cnt;
            tail = head;
            head = head->next;
        }
        return cnt;
    }
};