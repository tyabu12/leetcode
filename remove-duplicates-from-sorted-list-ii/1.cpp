/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
// time: O(N)
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        unordered_map<int, int> dupCounts;
        for (ListNode* cur = head; cur != NULL; cur = cur->next) {
            dupCounts[cur->val]++;
        }
        ListNode* prev = NULL;
        for (ListNode* cur = head; cur != NULL; cur = cur->next) {
            if (dupCounts[cur->val] == 1) {
                // No duplicate
                prev = cur;
            } else {
                // Since cur is duplicate, erase cur
                if (prev == NULL) {
                    head = cur->next;
                } else {
                    prev->next = cur->next;
                }
            }
        }
        return head;
    }
};
