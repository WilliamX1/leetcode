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
    ListNode* deleteNode(ListNode* head, int val) {
        ListNode* fake_head = new ListNode(!val); fake_head->next = head;
        ListNode* pre_ptr = fake_head, *cur_ptr = head;
        while (cur_ptr && cur_ptr->val != val) {
            pre_ptr = cur_ptr;
            cur_ptr = cur_ptr->next;
        };
        if (cur_ptr != nullptr) pre_ptr->next = cur_ptr->next;
        return fake_head->next;
    }
};