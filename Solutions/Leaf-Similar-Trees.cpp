
//   Definition for a binary tree node.
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr)
    {
    }
    TreeNode(int x) : val(x), left(nullptr), right(nullptr)
    {
    }
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right)
    {
    }
};

#include <bits/stdc++.h>

using namespace std;

class Solution
{
  public:
    void get(TreeNode *root, vector<int> &v)
    {
        if (root->left == nullptr && root->right == nullptr)
            v.push_back(root->val);

        if (root->left != nullptr)
            get(root->left, v);
        if (root->right != nullptr)
            get(root->right, v);
    };
    bool leafSimilar(TreeNode *root1, TreeNode *root2)
    {
        vector<int> v1, v2;
        get(root1, v1);
        get(root2, v2);
        return v1 == v2;
    }
};
int main()
{
    TreeNode *root1 = new TreeNode(1);
    TreeNode *root2 = new TreeNode(2);
    Solution S;
    S.leafSimilar(root1, root2);
    return 0;
}