/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution
{
  public:
    vector<vector<int>> levelOrder(TreeNode *root)
    {
        struct node
        {
            TreeNode *t;
            int layer;
            node(){};
            node(TreeNode *tt, int l) : t(tt), layer(l){};
        };
        deque<node *> d;
        if (root)
            d.push_back(new node(root, 0));

        vector<vector<int>> v;
        while (!d.empty())
        {
            node *cur = d.front();
            d.pop_front();
            if (v.size() <= cur->layer)
                v.push_back(vector<int>());
            v.back().push_back(cur->t->val);
            if (cur->t->left)
                d.push_back(new node(cur->t->left, cur->layer + 1));
            if (cur->t->right)
                d.push_back(new node(cur->t->right, cur->layer + 1));
        };
        return v;
    }
};