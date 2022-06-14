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
    bool _findTarget(TreeNode *root, int k, unordered_map<int, bool> &m)
    {
        if (root == nullptr)
            return false;
        if (m[k - root->val])
            return true;
        m[root->val] = true;
        return _findTarget(root->left, k, m) || _findTarget(root->right, k, m);
    };
    bool findTarget(TreeNode *root, int k)
    {
        unordered_map<int, bool> m;
        return _findTarget(root, k, m);
    }
};