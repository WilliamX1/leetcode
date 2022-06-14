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
    TreeNode *ans;
    bool _lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q)
    {
        if (root == nullptr)
            return false;
        bool mid = root == p || root == q;
        bool left = _lowestCommonAncestor(root->left, p, q);
        bool right = _lowestCommonAncestor(root->right, p, q);
        if (mid + left + right == 2)
            ans = root;
        return mid || left || right;
    };
    TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q)
    {
        _lowestCommonAncestor(root, p, q);
        return ans;
    }
};