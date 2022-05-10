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
    int _longestZigzag(TreeNode *root, bool isLeft, int& ans) {
        if (root == 0)
            return 0;

        int left =  _longestZigzag(root->left, true, ans);
        int right = _longestZigzag(root->right, false, ans);
        ans = max(ans, max(left, right) + 1);

        return isLeft ? 1 + right : 1 + left;
    };
    int longestZigZag(TreeNode* root) {
        if (root == NULL) return 0;

        int ans = 0;
        _longestZigzag(root, true, ans);
        return ans - 1;
    }
};