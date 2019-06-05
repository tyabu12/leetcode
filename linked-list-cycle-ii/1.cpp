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
    ListNode *detectCycle(ListNode *head) {
        unordered_set<ListNode*> s;
        for (ListNode *cur = head; cur != NULL; cur = cur->next) {
            auto itr = s.find(cur->next);
            if (itr != s.end()) return *itr;
            s.insert(cur);
        }
        return NULL;
    }
};
