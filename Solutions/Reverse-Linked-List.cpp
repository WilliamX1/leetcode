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
    ListNode* reverseList(ListNode* head) {
        if (head == nullptr) return nullptr;

        unordered_map<ListNode*, ListNode*> m;
        ListNode* p = head;
        while (p->next) {
            m[p->next] = p;
            p = p->next;
        };
        ListNode* new_head = p;
        while (p) {
            p = p->next = m[p];
        };
        return new_head;
    }
};