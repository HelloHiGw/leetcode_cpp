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
//     bool isPalindrome(ListNode* head) {
//         stack<ListNode*> st;
//         ListNode *curr = head;
//         while (curr) {
//             st.push(curr);
//             curr = curr->next;
//         }
//         while (head) {
//             if (head->val != st.top()->val) return false;
//             st.pop();
//             head = head->next;
//         }
//         return true;
//     }
// };


// class Solution {
// public:
//     bool isPalindrome(ListNode* head) {
//         ListNode *curr = head;
//         return isPalin(head, curr);
//     }
    
//     bool isPalin(ListNode *head, ListNode *&curr) {
//         if (!head) return true;
//         if (!isPalin(head->next, curr) || head->val != curr->val) return false;
//         curr = curr->next;
//         return true;
//     }
// };

class Solution {
public:
    bool isPalindrome(ListNode* head) {
        ListNode *dummy = new ListNode(-1), *slow = dummy, *fast = dummy;
        dummy->next = head;
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        ListNode *node = reverse(slow->next);
        while (node) {
            if (head->val != node->val) return false;
            head = head->next;
            node = node->next;
        }
        return true;
    }
    
    ListNode* reverse(ListNode* head) {
        ListNode *newHead = nullptr;
        while (head) {
            ListNode *nxt = head->next;
            head->next = newHead;
            newHead = head;
            head = nxt;
        }
        return newHead;
    }
};