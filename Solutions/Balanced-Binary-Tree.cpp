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
    int _isBalanced(TreeNode *root, bool &ans)
    {
        if (root == nullptr)
            return 0;

        int left = _isBalanced(root->left, ans), right = _isBalanced(root->right, ans);
        if (abs(left - right) > 1)
            ans = false;
        return max(left, right) + 1;
    };
    bool isBalanced(TreeNode *root)
    {
        bool ans = true;
        _isBalanced(root, ans);
        return ans;
    }
};