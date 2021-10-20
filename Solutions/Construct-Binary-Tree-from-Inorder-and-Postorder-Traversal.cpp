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
#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    TreeNode* _buildTree(vector<int>& inorder, int l_in, int r_in, vector<int>& postorder, int l_po, int r_po) {
        if (l_po > r_po) return nullptr;

        TreeNode* root = new TreeNode(postorder[r_po]);
        for (int i = l_in; i <= r_in; i++)
            if (root->val == inorder[i]) {
                root->left = _buildTree(inorder, l_in, i - 1, postorder, l_po, l_po + i - l_in - 1);
                root->right = _buildTree(inorder, i + 1, r_in, postorder, r_po - (r_in - i), r_po - 1);
                break;
            };
        return root;
    };
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        return _buildTree(inorder, 0, inorder.size() - 1, postorder, 0, postorder.size() - 1);
    }
};
