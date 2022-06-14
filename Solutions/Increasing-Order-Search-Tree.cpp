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
    vector<TreeNode *> v;
    void _increasingBST(TreeNode *root)
    {
        if (root == NULL)
            return;

        _increasingBST(root->left);
        v.push_back(root);
        _increasingBST(root->right);
        return;
    };
    TreeNode *increasingBST(TreeNode *root)
    {
        _increasingBST(root);
        int n = v.size();
        for (int i = 0; i < n - 1; i++)
        {
            v[i]->left = nullptr;
            v[i]->right = v[i + 1];
        };
        v[n - 1]->left = v[n - 1]->right = nullptr;
        return v[0];
    }
};