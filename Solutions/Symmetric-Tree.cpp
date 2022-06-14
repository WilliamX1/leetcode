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
    bool _isSymmectric(TreeNode *root1, TreeNode *root2)
    {
        if (root1 == nullptr && root2 == nullptr)
            return true;
        if (root1 == nullptr || root2 == nullptr)
            return false;
        if (root1->val != root2->val)
            return false;
        return _isSymmectric(root1->left, root2->right) && _isSymmectric(root1->right, root2->left);
    };
    bool isSymmetric(TreeNode *root)
    {
        return root == nullptr || _isSymmectric(root->left, root->right);
    };
};