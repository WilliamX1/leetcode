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
    ListNode *mergeNodes(ListNode *head)
    {
        ListNode *last = head, *next = head->next;
        vector<int> v;
        while (next != nullptr)
        {
            int cnt = 0;
            while (next != nullptr && next->val != 0)
            {
                cnt += next->val;
                next = next->next;
            };
            v.push_back(cnt);
            last = next;
            next = next->next;
        };
        ListNode *new_head = new ListNode(v.front()), *cur = new_head;
        for (int i = 1; i < v.size(); i++)
        {
            cur = cur->next = new ListNode(v[i]);
        };
        return new_head;
    }
};