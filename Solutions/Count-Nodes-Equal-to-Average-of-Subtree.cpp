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
    vector<int> _averageOfSubtree(TreeNode *root, int& ans) {
        if (root == NULL) return {0, 0};
        else {
            vector<int> left = _averageOfSubtree(root->left, ans);
            vector<int> right = _averageOfSubtree(root->right, ans);
            int tot = left[0] + right[0] + root->val;
            int cnt = left[1] + right[1] + 1;
            ans += tot / cnt == root->val;
            return {tot, cnt};
        };
    };
    int averageOfSubtree(TreeNode* root) {
        int ans = 0;
        _averageOfSubtree(root, ans);
        return ans;
    }
};