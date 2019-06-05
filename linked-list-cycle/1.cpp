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
    bool hasCycle(ListNode *head) {
        unordered_map<ListNode*, bool> m;
        for (ListNode *cur = head; cur != NULL; cur = cur->next) {
            if (m.find(cur->next) != m.end()) return true;
            m[cur->next] = true;
        }
        return false;
    }
};
