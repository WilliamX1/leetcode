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
    vector<int> _maxSumBST(TreeNode* root, int& ans) {
        if (root == NULL)
            return {true, 0, INT_MAX, INT_MIN};
        /* @ret: flag, tot, min, max */
        vector<int> left = _maxSumBST(root->left, ans);
        vector<int> right = _maxSumBST(root->right, ans);
        if (left[0] && right[0] && left[3] < root->val && right[2] > root->val) {
            ans = max(ans, left[1] + right[1] + root->val);
            return {true, left[1] + right[1] + root->val, min(root->val, min(left[2], right[2])), max(root->val, max(left[3], right[3]))};
        } else return {false, 0, 0, 0};
    };
    int maxSumBST(TreeNode* root) {
        int ans = 0;
        _maxSumBST(root, ans);
        return ans;
    }
};