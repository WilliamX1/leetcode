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
    int _maxPathSum(TreeNode *root, int &ans)
    {
        if (!root)
            return 0;

        int lvalue = 0, rvalue = 0;
        if (root->left)
            lvalue = _maxPathSum(root->left, ans);
        if (root->right)
            rvalue = _maxPathSum(root->right, ans);
        ans = max(lvalue + rvalue + root->val, ans);
        return max(max(lvalue, rvalue) + root->val, 0);
    };
    int maxPathSum(TreeNode *root)
    {
        int ans = -1e9;
        _maxPathSum(root, ans);
        return ans;
    };
};