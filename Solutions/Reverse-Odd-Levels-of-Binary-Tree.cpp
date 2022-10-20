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
    void _reverseOddLevels(TreeNode *left, TreeNode *right)
    {
        int tmp = left->val;
        left->val = right->val;
        right->val = tmp;

        if (left->left && left->left->left)
        {
            _reverseOddLevels(left->left->left, right->right->right);
            _reverseOddLevels(left->left->right, right->right->left);
            _reverseOddLevels(left->right->left, right->left->right);
            _reverseOddLevels(left->right->right, right->left->left);
        };
        return;
    };
    TreeNode *reverseOddLevels(TreeNode *root)
    {
        if (root->left)
            _reverseOddLevels(root->left, root->right);
        return root;
    }
};