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
class Solution {
public:
    void dfs(TreeNode* left, TreeNode* right, const int cur, int& ans) {
        ans = max(ans, cur + 1);

        if (left->left && right->right) dfs(left->left, right->right, 2 * cur + 1, ans);
        if (left->left && right->left) dfs(left->left, right->left, 2 * cur, ans);
        if (left->right && right->right) dfs(left->right, right->right, 2 * cur, ans);
        if (left->right && right->left) dfs(left->right, right->left, 2 * cur - 1, ans);

        return;
    };
    int widthOfBinaryTree(TreeNode* root) {
        if (root == nullptr) return 0;

        int ans = 0;
        dfs(root, root, 0, ans);
        return ans;
    }
};