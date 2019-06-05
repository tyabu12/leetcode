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
        unordered_set<ListNode*> s;
        for (ListNode *cur = head; cur != NULL; cur = cur->next) {
            if (s.count(cur->next) > 0) return true;
            s.insert(cur);
        }
        return NULL;
    }
};

