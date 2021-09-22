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
private:
    bool isSymmetric(TreeNode* rootA, TreeNode* rootB) {
        if (rootA == nullptr && rootB == nullptr) return true;
        if (rootA == nullptr || rootB == nullptr) return false;
        return rootA->val == rootB->val && isSymmetric(rootA->left, rootB->right) && isSymmetric(rootA->right, rootB->left);
    };
public:
    bool isSymmetric(TreeNode* root) {
        return isSymmetric(root, root);
    }
};