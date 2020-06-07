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
    vector<ListNode*> splitListToParts(ListNode* root, int k) {
        int count = 0;
        ListNode *curr = root;
        while (curr) {
            ++count;
            curr = curr->next;
        }
        int r = count % k, len = count / k;
        vector<ListNode*> res(k);
        ListNode *pre = nullptr;
        for (int i = 0; i < k && root; ++i, --r) {
            res[i] = root;
            for (int j = 0; j < len + (r > 0); ++j) {
                pre = root;
                root = root->next;
            }
            pre->next = nullptr;
        }
        return res;
    }
};