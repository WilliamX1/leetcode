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
class Solution
{
  public:
    ListNode *removeElements(ListNode *head, int val)
    {
        ListNode *new_head = head;
        while (new_head && new_head->val == val)
            new_head = new_head->next;
        if (!new_head)
            return nullptr;

        ListNode *cur_node = new_head, *next_node = new_head->next;
        while (next_node)
        {
            while (next_node && next_node->val == val)
                next_node = next_node->next;
            cur_node = cur_node->next = next_node;
            if (next_node)
                next_node = next_node->next;
            else
                break;
        };
        return new_head;
    }
};