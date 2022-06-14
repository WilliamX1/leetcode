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
    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2)
    {
        ListNode *ptr1 = l1, *ptr2 = l2;
        if (ptr1 == nullptr)
            return ptr2;
        if (ptr2 == nullptr)
            return ptr1;

        ListNode *head = nullptr;
        if (ptr1->val < ptr2->val)
        {
            head = ptr1;
            ptr1 = ptr1->next;
        }
        else
        {
            head = ptr2;
            ptr2 = ptr2->next;
        };

        ListNode *ptr = head;
        while (ptr1 && ptr2)
        {
            if (ptr1->val < ptr2->val)
            {
                ptr = ptr->next = ptr1;
                ptr1 = ptr1->next;
            }
            else
            {
                ptr = ptr->next = ptr2;
                ptr2 = ptr2->next;
            };
        };
        while (ptr1)
        {
            ptr = ptr->next = ptr1;
            ptr1 = ptr1->next;
        };
        while (ptr2)
        {
            ptr = ptr->next = ptr2;
            ptr2 = ptr2->next;
        };
        return head;
    }
};