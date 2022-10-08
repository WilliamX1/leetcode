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
    TreeNode *expandBinaryTree(TreeNode *root)
    {
        if (root == nullptr)
            return root;
        if (root->left && root->val != -1)
            root->left = new TreeNode(-1, root->left, nullptr);
        if (root->right && root->val != -1)
            root->right = new TreeNode(-1, nullptr, root->right);
        expandBinaryTree(root->left);
        expandBinaryTree(root->right);
        return root;
    };
};