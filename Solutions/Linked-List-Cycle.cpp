/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
#include <set>

using namespace std;

class Solution
{
  public:
    bool hasCycle(ListNode *head)
    {
        set<ListNode *> m;
        ListNode *p = head;
        while (p != NULL)
        {
            if (m.find(p) != m.end())
                return true;
            else
                m.insert(p);
            p = p->next;
        };
        return false;
    };
};