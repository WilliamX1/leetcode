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
    ListNode *removeNthFromEnd(ListNode *head, int n)
    {
        if (head == nullptr || head->next == nullptr)
            return nullptr;

        ListNode *cur = head, *shift = cur;
        for (int i = 0; i < n; i++)
            shift = shift->next;
        if (shift == nullptr)
        {
            cur = head->next;
            delete head;
            return cur;
        }
        else
            shift = shift->next;

        while (shift != nullptr)
        {
            cur = cur->next;
            shift = shift->next;
        };
        shift = cur->next;
        cur->next = shift->next;
        delete shift;
        return head;
    }
};