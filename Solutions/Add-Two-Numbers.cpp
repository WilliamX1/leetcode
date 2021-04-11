#include <vector>

using namespace std;

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
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        if (l1 == nullptr && l2 == nullptr) return nullptr;

        ListNode* res = new ListNode();
        ListNode* head = res, *prev;
        
        bool carry = 0; //进位
        ListNode* cursorL1 = l1, *cursorL2 = l2;
        while (cursorL1 != nullptr && cursorL2 != nullptr) {
            res->val = (carry + cursorL1->val + cursorL2->val) % 10;
            carry = (carry + cursorL1->val + cursorL2->val) / 10;
            /*记录前一个节点*/
            prev = res;
            res = res->next = new ListNode();
            /*迭代*/
            cursorL1 = cursorL1->next;
            cursorL2 = cursorL2->next;
        };
        while (cursorL1 != nullptr) {
            res->val = (carry + cursorL1->val) % 10;
            carry = (carry + cursorL1->val ) / 10;
            /*记录前一个节点*/
            prev = res;
            res = res->next = new ListNode();
            /*迭代*/
            cursorL1 = cursorL1->next;
        };
        while (cursorL2 != nullptr) {
            res->val = (carry + cursorL2->val) % 10;
            carry = (carry + cursorL2->val) / 10;
            /*记录前一个节点*/
            prev = res;
            res = res->next = new ListNode();
            /*迭代*/
            cursorL2 = cursorL2->next;
        };
        
        if (carry) res->val = 1;
        else prev->next = nullptr;

        return head;
    }
};

int main()
{
    Solution S;
    return 0;
}