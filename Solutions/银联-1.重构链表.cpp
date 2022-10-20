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
    ListNode *reContruct(ListNode *head)
    {
        ListNode *fake_head = new ListNode();
        fake_head->next = head;

        ListNode *p1 = fake_head, *p2 = head;
        while (p2)
        {
            if ((p2->val & 1) == 0)
                p2 = p1->next = p2->next;
            else
            {
                p1 = p2;
                p2 = p2->next;
            };
        };
        return fake_head->next;
    }
};