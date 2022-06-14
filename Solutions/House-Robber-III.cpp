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
    vector<int> _rob(TreeNode *root)
    {
        if (root == NULL)
            return {0, 0};

        vector<int> left = _rob(root->left), right = _rob(root->right);
        // cout << root->val << ' ' << left[0] << ' ' << left[1] << ' ' << right[0] << ' ' << right[1] << endl;
        return {max(left[0], left[1]) + max(right[0], right[1]), left[0] + right[0] + root->val};
    }
    int rob(TreeNode *root)
    {
        vector<int> ans = _rob(root);
        return max(ans[0], ans[1]);
    }
};