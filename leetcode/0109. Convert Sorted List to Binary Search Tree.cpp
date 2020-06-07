/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
// class Solution {
// public:
//     TreeNode* sortedListToBST(ListNode* head) {
//         return buildBST(head, nullptr);
//     }
    
//     TreeNode* buildBST(ListNode *head, ListNode *tail) {
//         if (head == tail) return nullptr;
//         ListNode *slow = head, *fast = head;
//         while (fast != tail && fast->next != tail) {
//             fast = fast->next->next;
//             slow = slow->next;
//         }
//         TreeNode *root = new TreeNode(slow->val);
//         root->left = buildBST(head, slow);
//         root->right = buildBST(slow->next, tail);
//         return root;
//     }
// };


class Solution {
public:
    TreeNode* sortedListToBST(ListNode* head) {
        int cnt = 0;
        ListNode *curr = head;
        while (curr) {
            ++cnt;
            curr = curr->next;
        }
        return buildBST(head, 0, cnt - 1);
    }
    
    TreeNode* buildBST(ListNode *&head, int start, int end) {
        if (start > end) return nullptr;
        int mid = start + (end - start) / 2;
        TreeNode *left = buildBST(head, start, mid - 1);
        TreeNode *root = new TreeNode(head->val);
        root->left = left;
        head = head->next;
        root->right = buildBST(head, mid + 1, end);
        return root;
    }
};