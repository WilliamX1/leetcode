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
    int numComponents(ListNode *head, vector<int> &nums)
    {
        set<int> s;
        for (const int &num : nums)
            s.insert(num);

        ListNode *ptr = head;
        int ans = 0;
        while (ptr)
        {
            if (s.count(ptr->val))
            {
                ans++;
                while ((ptr = ptr->next) != nullptr && s.count(ptr->val))
                    ;
            }
            else
                ptr = ptr->next;
        };
        return ans;
    }
};