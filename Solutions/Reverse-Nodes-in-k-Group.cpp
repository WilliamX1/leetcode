/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* p = head;
        for (int i = 0; i < k; i++) {
            if (p == nullptr) return head;
            else p = p->next;
        };
        ListNode* p1 = head, *p2 = head->next, *p3;
        for (int i = 1; i < k; i++) {
            p3 = p2->next;
            p2->next = p1;
            p1 = p2;
            p2 = p3;
        };
        head->next = reverseKGroup(p, k);
        return p1;
    }
};