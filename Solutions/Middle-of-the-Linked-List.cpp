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
    ListNode *middleNode(ListNode *head)
    {
        if (head == nullptr)
            return head;

        ListNode *last = head, *next = head->next;

        while (next)
        {
            last = last->next;
            next = next->next;
            if (next)
                next = next->next;
        };

        return last;
    }
};