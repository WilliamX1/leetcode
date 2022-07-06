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
    TreeNode *insertIntoMaxTree(TreeNode *root, int val)
    {
        if (root->val < val)
            return new TreeNode(val, root, nullptr);
        TreeNode *p = root;
        while (p)
        {
            if (p->right && p->right->val >= val)
                p = p->right;
            else
            {
                TreeNode *newnode = new TreeNode(val, p->right, nullptr);
                p->right = newnode;
                break;
            };
        };
        return root;
    }
};