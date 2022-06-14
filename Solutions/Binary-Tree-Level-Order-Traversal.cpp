/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
#include <bits/stdc++.h>

using namespace std;

class Solution
{
  public:
    struct node
    {
        TreeNode *root;
        int level;
        node() : root(nullptr), level(-1){};
        node(TreeNode *r, int l) : root(r), level(l){};
    };
    vector<vector<int>> levelOrder(TreeNode *root)
    {
        vector<vector<int>> ans;
        queue<node> q;
        if (root)
            q.push(node(root, 0));

        while (!q.empty())
        {
            node cur = q.front();
            q.pop();
            if (ans.size() <= cur.level)
                ans.emplace_back(vector<int>());
            (ans.back()).push_back((cur.root)->val);
            if ((cur.root)->left)
                q.push(node((cur.root)->left, cur.level + 1));
            if ((cur.root)->right)
                q.push(node((cur.root)->right, cur.level + 1));
        };
        return ans;
    }
};