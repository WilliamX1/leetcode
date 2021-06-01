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
#include <stack>

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        std::stack<ListNode*> ans;
        while (l1 != nullptr && l2 != nullptr) {
            if (l1->val <= l2->val) {
                ans.push(l1);
                l1 = l1->next;
            } else {
                ans.push(l2);
                l2 = l2->next;
            };
        };
        while (l1 != nullptr) {
            ans.push(l1);
            l1 = l1->next;
        };
        while (l2 != nullptr) {
            ans.push(l2);
            l2 = l2->next;
        };

        ListNode* last = nullptr;
        if (!ans.empty()) {
            last = ans.top();
            ans.pop();
        };
        while (!ans.empty()) {
            ListNode* cur = ans.top();
            ans.pop();
            cur->next = last;
            last = cur;
        };
        return last;
    }
};