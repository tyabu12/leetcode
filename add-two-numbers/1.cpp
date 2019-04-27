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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *ltop = NULL, *lprev;
        int carry = 0;
        while (l1 != NULL || l2 != NULL) {
            int sumVal = carry;
            if (l1 != NULL) sumVal += l1->val;
            if (l2 != NULL) sumVal += l2->val;
            carry = sumVal/10;
            sumVal %= 10;
            ListNode* node = new ListNode(sumVal);
            if (ltop == NULL) ltop = node;
            else lprev->next = node;
            lprev = node;
            if (l1 != NULL) l1 = l1->next;
            if (l2 != NULL) l2 = l2->next;
        }
        if (carry > 0) {
            ListNode* node = new ListNode(carry);
            lprev->next = node;
            lprev = node;
        }
        return ltop;
    }
};
