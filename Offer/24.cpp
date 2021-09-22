/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* left = nullptr, *mid = head, *right = head ? mid->next : nullptr;
        while (mid) {
            mid->next = left;
            left = mid;
            mid = right;
            if (right) right = right->next;
        };
        
        return left;
    }
};