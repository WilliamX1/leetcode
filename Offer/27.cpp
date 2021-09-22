/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* mirrorTree(TreeNode* root) {
        if (root != nullptr) {
            TreeNode* left = root->left, *right = root->right;
            root->left = mirrorTree(right);
            root->right = mirrorTree(left);
        };
        return root;
    }
};