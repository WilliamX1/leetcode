/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution
{
  public:
    ListNode *detectCycle(ListNode *head)
    {
        if (!head)
            return NULL;
        ListNode *p = head, *pre = head, *next = head;
        while (pre->next && next->next && next->next->next)
        {
            pre = pre->next;
            next = next->next->next;
            if (pre == next)
            {
                while (p != pre)
                {
                    p = p->next;
                    pre = pre->next;
                };
                return p;
            };
        };
        return NULL;
    };
};