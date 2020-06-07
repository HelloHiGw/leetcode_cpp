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
//     ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
//         int lenA = getLen(headA), lenB = getLen(headB);
//         if (lenA < lenB) {
//             swap(headA, headB);
//             swap(lenA, lenB);
//         }
//         for (int i = 0; i < lenA - lenB; ++i) headA = headA->next;
//         while (headA) {
//             if (headA == headB) return headA;
//             headA = headA->next;
//             headB = headB->next;
//         }
//         return nullptr;
//     }
    
//     int getLen(ListNode *head) {
//         int len = 0;
//         while (head) {
//             ++len;
//             head = head->next;
//         }
//         return len;
//     }
// };


class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if (!headA || !headB) return nullptr;
        ListNode *currA = headA, *currB = headB;
        while (currA != currB) {
            currA = currA ? currA->next : headB;
            currB = currB ? currB->next : headA;
        }
        return currA;
    }
};