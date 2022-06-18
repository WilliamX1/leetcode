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
    vector<int> get(TreeNode *root)
    {
        if (!root)
            return {};
        else
        {
            vector<int> left = get(root->left);
            vector<int> right = get(root->right);
            vector<int> v = {root->val};
            v.insert(v.end(), left.begin(), left.end());
            v.insert(v.end(), right.begin(), right.end());
            return v;
        }
    }
    vector<int> getAllElements(TreeNode *root1, TreeNode *root2)
    {
        vector<int> v1 = get(root1), v2 = get(root2);
        v1.insert(v1.end(), v2.begin(), v2.end());
        sort(v1.begin(), v1.end());
        return v1;
    }
};