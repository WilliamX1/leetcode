/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution
{
  private:
    int f(TreeNode *root, bool &flag)
    {
        if (root == nullptr || !flag)
            return 0;
        else
        {
            int left_height = f(root->left, flag), right_height = f(root->right, flag);
            if (abs(left_height - right_height) > 1)
                flag = false;
            return max(left_height, right_height) + 1;
        };
    }

  public:
    bool isBalanced(TreeNode *root)
    {
        bool flag = true;
        f(root, flag);
        return flag;
    }
};