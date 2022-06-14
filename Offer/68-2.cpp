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
  private:
    stack<TreeNode *> s1, s2;
    bool getPath(TreeNode *root, TreeNode *p, stack<TreeNode *> &s)
    {
        if (root == nullptr)
            return false;
        else if (root->val == p->val || getPath(root->left, p, s) || getPath(root->right, p, s))
        {
            s.push(root);
            return true;
        }
        else
            return false;
    };

  public:
    TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q)
    {
        getPath(root, p, s1);
        getPath(root, q, s2);
        TreeNode *ans;
        while (!s1.empty() && !s2.empty() && s1.top() == s2.top())
        {
            ans = s1.top();
            s1.pop();
            s2.pop();
        };
        return ans;
    }
};