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
#include <bits/stdc++.h>

using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr)
    {
    }
    ListNode(int x) : val(x), next(nullptr)
    {
    }
    ListNode(int x, ListNode *next) : val(x), next(next)
    {
    }
};
class Solution
{
  private:
    ListNode *_sortList(ListNode *head, int size)
    {
        if (size == 1)
        {
            ListNode *new_head = head;
            new_head->next = nullptr;
            return new_head;
        }

        int m = size >> 1;
        ListNode *mid = head;
        for (int i = 0; i < m; i++)
            mid = mid->next;

        /* 归并 */
        ListNode *ptr_head = _sortList(head, m), *ptr_mid = _sortList(mid, size - m);
        ListNode *new_head = nullptr, *ptr = nullptr;
        if (ptr_head->val < ptr_mid->val)
        {
            ptr = new_head = ptr_head;
            ptr_head = ptr_head->next;
        }
        else
        {
            ptr = new_head = ptr_mid;
            ptr_mid = ptr_mid->next;
        };

        while (ptr_head != nullptr && ptr_mid != nullptr)
        {
            if (ptr_head->val < ptr_mid->val)
            {
                ptr = ptr->next = ptr_head;
                ptr_head = ptr_head->next;
            }
            else
            {
                ptr = ptr->next = ptr_mid;
                ptr_mid = ptr_mid->next;
            };
        };

        while (ptr_head != nullptr)
        {
            ptr = ptr->next = ptr_head;
            ptr_head = ptr_head->next;
        };

        while (ptr_mid != nullptr)
        {
            ptr = ptr->next = ptr_mid;
            ptr_mid = ptr_mid->next;
        };
        ptr->next = nullptr;

        return new_head;
    };

  public:
    ListNode *sortList(ListNode *head)
    {
        ListNode *ptr = head;
        int size = 0;
        while (ptr)
        {
            size++;
            ptr = ptr->next;
        };
        return size ? _sortList(head, size) : nullptr;
    }
};

int main()
{
    ListNode *n1 = new ListNode(-1);
    ListNode *n2 = new ListNode(5);
    ListNode *n3 = new ListNode(3);
    ListNode *n4 = new ListNode(4);
    ListNode *n5 = new ListNode(0);
    n1->next = n2;
    n2->next = n3;
    n3->next = n4;
    n4->next = n5;
    Solution S;
    S.sortList(n1);
    return 0;
}