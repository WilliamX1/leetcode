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
    bool isPalindrome(ListNode *head)
    {
        vector<int> v;
        ListNode *p = head;
        while (p != nullptr)
        {
            v.push_back(p->val);
            p = p->next;
        };
        int n = v.size();
        int left = 0;
        while (left < n && v[left] == v[n - left - 1])
            left++;
        if (left == n)
            return true;
        else
        {
            int right = n - left - 1;
            bool flag1 = true, flag2 = true;
            for (int i = 0; i < right - left; i++)
            {
                if (v[left + i] != v[right - i - 1])
                    flag1 = false;
                if (v[right - i] != v[left + i + 1])
                    flag2 = false;
            };
            return flag1 || flag2;
        };
    }
};