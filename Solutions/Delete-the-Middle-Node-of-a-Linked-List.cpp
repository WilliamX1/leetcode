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
    ListNode* deleteMiddle(ListNode* head) {
        if (!head->next) return NULL;

        int len = 0;
        ListNode* p = head;
        while (p != NULL) {
            len++;
            p = p->next;
        };
        int cnt = len / 2;
        p = head;
        while (--cnt > 0) p = p->next;
        p->next = p->next->next;
        return head;
    }
};