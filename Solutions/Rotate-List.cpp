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
    ListNode *rotateRight(ListNode *head, int k)
    {
        if (!head)
            return head;
        int len = 1;
        ListNode *p = head, *tail;
        while (p->next)
        {
            len++;
            p = p->next;
        };
        tail = p;
        tail->next = head;

        k = len - k % len;
        p = head;
        while (--k > 0)
            p = p->next;
        ListNode *new_head = p->next;
        p->next = NULL;
        return new_head;
    }
};