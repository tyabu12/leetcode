/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
// recursively
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if (head == NULL) return NULL;
        if (head->next == NULL) return head;
        ListNode *newTail = head->next;
        ListNode *newHead = reverseList(head->next);
        newTail->next = head;
        head->next = NULL;
        return newHead;
    }
};
