#include <bits/stdc++.h>

using namespace std;

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
    struct node
    {
        /* data */
        int val;
        int idx;
        node() {};
        node(int v, int i) : val(v), idx(i) {};
        bool operator > (const node& b) const {
            return this->val > b.val;
        };
    };
    
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int n = lists.size();
        vector<ListNode*> iters(n);
        priority_queue<node, vector<node>, greater<node>> prepare;
        for (int i = 0; i < n; i++)
        {
            iters[i] = lists[i];
            if (iters[i] != nullptr) prepare.push(node(iters[i]->val, i));
        }
        vector<ListNode*> ans;
        while (!prepare.empty()) {
            node cur = prepare.top();
            prepare.pop();

            ListNode* newListNode = new ListNode(iters[cur.idx]->val);
            if (!ans.empty()) (ans.back())->next = newListNode;
            ans.push_back(newListNode);

            if (iters[cur.idx]->next != nullptr) {
                iters[cur.idx] = iters[cur.idx]->next;
                prepare.push(node(iters[cur.idx]->val, cur.idx));
            } else iters[cur.idx] = iters[cur.idx]->next;
        };
        if (ans.empty()) return nullptr;
        else return ans.front();
    }
};

int main()
{

}