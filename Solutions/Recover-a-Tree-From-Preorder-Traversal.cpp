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
class Solution
{
  public:
    struct node
    {
        TreeNode *tnode;
        int level;
        node(TreeNode *t, int l) : tnode(t), level(l){};
    };
    TreeNode *recoverFromPreorder(string traversal)
    {
        int idx = 0;
        while (idx < traversal.size() && traversal[idx] != '-')
            idx++;
        TreeNode *root = new TreeNode(stoi(traversal.substr(0, idx)));

        stack<node> stk;
        stk.push(node(root, 0));

        while (idx < traversal.size())
        {
            int level = 0;
            while (traversal[idx] == '-')
            {
                level++;
                idx++;
            };
            int start_idx = idx;
            while (idx < traversal.size() && traversal[idx] != '-')
                idx++;

            TreeNode *tn = new TreeNode(stoi(traversal.substr(start_idx, idx - start_idx)));

            while (!stk.empty() && stk.top().level - level != -1)
                stk.pop();
            if (stk.top().tnode->left == nullptr)
                stk.top().tnode->left = tn;
            else
                stk.top().tnode->right = tn;
            stk.push(node(tn, level));
        };
        return root;
    }
};