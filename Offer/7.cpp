/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

#include <bits/stdc++.h>

using namespace std;

class Solution
{
  private:
    unordered_map<int, int> m;
    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder, int preorder_left, int preorder_right,
                        int inorder_left, int inorder_right)
    {
        if (preorder_left > preorder_right)
            return nullptr;

        int ele = preorder[preorder_left];
        int idx = m[ele];
        return new TreeNode(
            ele,
            buildTree(preorder, inorder, preorder_left + 1, preorder_left + idx - inorder_left, inorder_left, idx - 1),
            buildTree(preorder, inorder, preorder_right - (inorder_right - idx) + 1, preorder_right, idx + 1,
                      inorder_right));
    };

  public:
    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder)
    {
        for (int i = 0; i < inorder.size(); i++)
        {
            m[inorder[i]] = i;
        };
        return buildTree(preorder, inorder, 0, preorder.size() - 1, 0, inorder.size() - 1);
    }
};