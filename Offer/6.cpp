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
    vector<int> reversePrint(ListNode* head) {
        stack<int> s;
        ListNode* ptr = head;
        while (ptr != nullptr) {
            s.push(ptr->val);
            ptr = ptr->next;
        };
        vector<int> v;
        while (!s.empty()) {
            v.push_back(s.top());
            s.pop();
        };
        return v;
    }
};