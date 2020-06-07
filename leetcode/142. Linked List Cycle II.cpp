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
//     ListNode *detectCycle(ListNode *head) {
//         ListNode *slow = head, *fast = head;
//         bool hasCircle = false;
//         while (fast && fast->next) {
//             fast = fast->next->next;
//             slow = slow->next;
//             if (slow == fast) {
//                 hasCircle = true;
//                 break;
//             }
//         }
//         if (!hasCircle) return nullptr;
//         unordered_map<ListNode*, bool> visited;
//         while (head) {
//             if (visited[head]) return head;
//             visited[head] = true;
//             head = head->next;
//         }
//         return nullptr;
//     }
// };

class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode *slow = head, *fast = head;
        bool hasCircle = false;
        while (fast && fast->next) {
            fast = fast->next->next;
            slow = slow->next;
            if (slow == fast) {
                hasCircle = true;
                break;
            }
        }
        if (!hasCircle) return nullptr;
        slow = head;
        while (slow != fast) {
            slow = slow->next;
            fast = fast->next;
        }
        return slow;
    }
};

/*
To understand this solution, you just need to ask yourself these question.
Assume the distance from head to the start of the loop is x1
the distance from the start of the loop to the point fast and slow meet is x2
the distance from the point fast and slow meet to the start of the loop is x3
What is the distance fast moved? What is the distance slow moved? And their relationship?

x1 + x2 + x3 + x2
x1 + x2
x1 + x2 + x3 + x2 = 2 (x1 + x2)
Thus x1 = x3
so head and fast move simultaneously, then they meet at circle start
*/