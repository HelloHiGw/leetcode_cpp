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
//     ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
//         l1 = reverse(l1);
//         l2 = reverse(l2);
//         int carry = 0;
//         ListNode *head = nullptr;
//         while (l1 || l2 || carry) {
//             int d1 = l1 ? l1->val : 0;
//             int d2 = l2 ? l2->val : 0;
//             if (l1) l1 = l1->next;
//             if (l2) l2 = l2->next;
//             int sum = d1 + d2 + carry;
//             carry = sum / 10;
//             ListNode *curr = new ListNode(sum % 10);
//             curr->next = head;
//             head = curr;
//         }
//         return head;
//     }
    
//     ListNode *reverse(ListNode *head) {
//         ListNode *newHead = nullptr;
//         while (head) {
//             ListNode *next = head->next;
//             head->next = newHead;
//             newHead = head;
//             head = next;
//         }
//         return newHead;
//     }
// };


// class Solution {
// public:
//     ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
//         stack<ListNode*> st1, st2;
//         while (l1) {
//             st1.push(l1);
//             l1 = l1->next;
//         }
//         while (l2) {
//             st2.push(l2);
//             l2 = l2->next;
//         }
//         int carry = 0;
//         ListNode *head = nullptr;
//         while (!st1.empty() || !st2.empty() || carry) {
//             int d1 = 0, d2 = 0;
//             if (!st1.empty()) {
//                 d1 = st1.top()->val;
//                 st1.pop();
//             }
//             if (!st2.empty()) {
//                 d2 = st2.top()->val;
//                 st2.pop();
//             }
//             int sum = d1 + d2 + carry;
//             carry = sum / 10;
//             ListNode *curr = new ListNode(sum % 10);
//             curr->next = head;
//             head = curr;
//         }
//         return head;
//     }
// };

// reverse add O(1) space
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int n1 = getLength(l1), n2 = getLength(l2);
        ListNode *head = nullptr;
        if (n1 < n2) swap(l1, l2);
        for (int i = 0; i < abs(n1 - n2); ++i) {  // here do not forget abs for n1 < n2
            addFront(head, l1->val);
            l1 = l1->next;
        }
        while (l1) {  // add from upper bit to down bit
            int sum = l1->val + l2->val;
            addFront(head, sum);  // later we want add carry from low bit of res to high bit of res, so here we add front, thus low bit of res is the head
            l1 = l1->next;
            l2 = l2->next;
        }
        int carry = 0;
        ListNode *newHead = nullptr;
        while (head) {  // change the val of head, and insertion in front to recover order
            ListNode *next = head->next;
            int sum = head->val + carry;
            carry = sum / 10;
            head->val = sum % 10;
            head->next = newHead;
            newHead = head;
            head = next;
        }
        if (carry) addFront(newHead, 1);
        return newHead;
    }
    
    int getLength(ListNode *head) {
        int cnt = 0;
        while (head) {
            ++cnt;
            head = head->next;
        }
        return cnt;
    }
    
    void addFront(ListNode *&head, int val) {
        ListNode *node = new ListNode(val);
        node->next = head;
        head = node;
    }
};