/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
// time: O(n)
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* prev = NULL;
        for (ListNode* cur = head; cur != NULL; cur = cur->next) {
            if (prev != NULL && prev->val == cur->val) {
                prev->next = cur->next;
            } else {
                prev = cur;
            }
        }
        return head;
    }
};
