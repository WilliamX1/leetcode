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
    ListNode *partition(ListNode *head, int x)
    {
        ListNode *dummyNode = new ListNode(0, head);
        ListNode *left = nullptr, *right = nullptr, *p = dummyNode;
        while (p = p->next)
            if (p->val < x && !left)
                left = p;
            else if (p->val >= x && !right)
                right = p;

        ListNode *copyleft = left, *copyright = right;

        ListNode *pre = dummyNode, *cur = pre->next, *next;

        while (cur && left && right)
        {
            next = cur->next;
            // cout << cur->val << ' ';
            if (cur->val < x)
            {
                if (cur == left || cur == left->next)
                {
                    left = cur;
                    pre = cur;
                    cur = next;
                }
                else
                {
                    pre->next = next;
                    cur->next = left->next;
                    left = left->next = cur;

                    cur = pre->next = next;
                };
            }
            else if (cur->val >= x)
            {
                if (cur == right || cur == right->next)
                {
                    right = cur;
                    pre = cur;
                    cur = next;
                }
                else
                {
                    pre->next = next;
                    cur->next = right->next;
                    right = right->next = cur;

                    cur = pre->next = next;
                };
            }
            else
            {
                pre = cur;
                cur = next;
            };
        };
        if (left && right && copyright == dummyNode->next)
        {
            dummyNode->next = copyleft;
            left->next = copyright;
            right->next = nullptr;
        }
        return dummyNode->next;
    }
};