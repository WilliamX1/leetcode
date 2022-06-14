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
    void dfs(TreeNode *root, vector<TreeNode *> &v)
    {
        v.push_back(root);
        if (root->left)
            dfs(root->left, v);
        if (root->right)
            dfs(root->right, v);
        return;
    };
    void flatten(TreeNode *root)
    {
        vector<TreeNode *> v;
        if (root)
            dfs(root, v);
        int len = v.size();
        for (int i = 0; i < len - 1; i++)
            v[i]->left = nullptr, v[i]->right = v[i + 1];
        v[len - 1]->left = v[len - 1]->right = nullptr;
        return;
    }
};