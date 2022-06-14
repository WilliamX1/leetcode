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
  private:
    void pre_traverse(TreeNode *root, vector<int> &v)
    {
        if (root == nullptr)
            return;
        pre_traverse(root->left, v);
        v.push_back(root->val);
        pre_traverse(root->right, v);
        return;
    };

  public:
    int kthSmallest(TreeNode *root, int k)
    {
        vector<int> v;
        pre_traverse(root, v);
        return v[k - 1];
    }
};