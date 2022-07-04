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
    ListNode *deleteDuplicates(ListNode *head)
    {
        ListNode *dummyNode = new ListNode(0, head);
        ListNode *pre = dummyNode, *cur = dummyNode->next, *next;
        while (cur)
        {
            next = cur;
            while (next && cur->val == next->val)
                next = next->next;
            if (cur->next == next)
            {
                pre = cur;
                cur = next;
            }
            else
            {
                cur = pre->next = next;
            };
        }
        return dummyNode->next;
    }
};