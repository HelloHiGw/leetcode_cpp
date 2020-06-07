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
//     vector<int> nextLargerNodes(ListNode* head) {
//         vector<int> res;
//         while (head) {
//             ListNode *node = head->next;
//             while (node && node->val <= head->val) node = node->next;
//             int val = node ? node->val : 0;
//             res.push_back(val);
//             head = head->next;
//         }
//         return res;
//     }
// };


// class Solution {
// public:
//     vector<int> nextLargerNodes(ListNode* head) {
//         head = reverseList(head);
//         stack<int> st;
//         vector<int> res;
//         while (head) {
//             while (!st.empty() && st.top() <= head->val) st.pop();
//             int greater = st.empty() ? 0 : st.top();
//             res.push_back(greater);
//             st.push(head->val);
//             head = head->next;
//         }
//         reverse(res.begin(), res.end());
//         return res;
//     }
    
//     ListNode *reverseList(ListNode *head) {
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


class Solution {
public:
    vector<int> nextLargerNodes(ListNode* head) {
        stack<int> st;
        vector<int> res;
        int index = 0;
        for (ListNode *curr = head; curr; curr = curr->next) {
            while(!st.empty() && res[st.top()] < curr->val) {
                res[st.top()] = curr->val;
                st.pop();
            }
            st.push(index++);
            res.push_back(curr->val);
        }
        while (!st.empty()) {
            res[st.top()] = 0;
            st.pop();
        }
        return res;
    }
};

/*
Push nodes' values to vector<int> res.
stack will save the indices of elements that need to find next greater element.
In the end, we reset 0 to all elements that have no next greater elements.
*/