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
    void _allPossibleFBT(int n, vector<vector<TreeNode *>> &v)
    {
        if (n == 1)
            v[1].push_back(new TreeNode(0));
        else
        {
            _allPossibleFBT(n - 2, v);
            for (int i = 1; i < n - 1; i += 2)
                for (TreeNode *left : v[i])
                    for (TreeNode *right : v[n - 1 - i])
                    {
                        TreeNode *root = new TreeNode(0, left, right);
                        v[n].push_back(root);
                    };
        };
    }
    vector<TreeNode *> allPossibleFBT(int n)
    {
        if (!(n & 1))
            return {};

        vector<vector<TreeNode *>> v(n + 1);
        _allPossibleFBT(n, v);
        return v[n];
    }
};