#include<bits/stdc++.h>

using namespace std;

// Definition for a Node.
// class Node {
// public:
//     int val;
//     Node* next;
//     Node* random;
    
//     Node(int _val) {
//         val = _val;
//         next = NULL;
//         random = NULL;
//     }
// };

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if (head == nullptr) return nullptr;

        unordered_map<Node*, Node*> m;
        Node* new_head = new Node(head->val);
        m[head] = new_head;

        Node* ptr = head, *new_ptr = new_head;
        while (ptr->next) {
            ptr = ptr->next;
            new_ptr = new_ptr->next = new Node(ptr->val);
            m[ptr] = new_ptr;
        };

        ptr = head;
        while (ptr) {
            m[ptr]->random = m[ptr->random];
            ptr = ptr->next;
        };
        return new_head;
    }
};