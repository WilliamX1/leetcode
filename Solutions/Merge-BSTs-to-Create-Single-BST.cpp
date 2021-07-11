
// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> v;
    void dfs(TreeNode* root)
    {
        if (root->left) dfs(root->left);
        v.push_back(root->val);
        if (root->right) dfs(root->right);
        return;
    };
    TreeNode* canMerge(vector<TreeNode*>& trees) {
        unordered_map<int, TreeNode*> m;
        int len = trees.size(), count = 0;
        vector<bool> flag(len, 0);
        for (int i = 0; i < len; i++) {
            queue<TreeNode*> q; if (trees[i]) q.push(trees[i]);
            bool ans = false;
            while(!q.empty())
            {
                TreeNode* cur = q.front(); q.pop(); count++;
                if (!cur->left && !cur->right)
                    if (!ans) continue;
                    else m.insert(make_pair(cur->val, cur));

                if (cur->left) q.push(cur->left);
                if (cur->right) q.push(cur->right);
                ans = true;
            };
        };
        TreeNode* head = nullptr;
        for (int i = 0; i < len; i++)
        {
            auto iter = m.find(trees[i]->val);
            if (iter != m.end()) {
                (iter->second)->left = trees[i]->left;
                (iter->second)->right = trees[i]->right;
            } else if (head == nullptr) head = trees[i];
            else return nullptr;
        };
        if (head == nullptr) return nullptr;
        else {
            dfs(head);
            int len = v.size();

            for (int i = 1; i < len; i++)
                if (v[i] <= v[i - 1]) return nullptr;
            return head;
        }
    };
}; 