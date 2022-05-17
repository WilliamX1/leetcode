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
    vector<int> _countPairs(TreeNode *root, int distance, int& ans) {
        vector<int> res(distance + 1, 0);
        if (root == nullptr)
            return res;
        if (root->left == nullptr && root->right == nullptr) {
            res[1] = 1;
            return res;
        }
        vector<int> left = _countPairs(root->left, distance, ans);
        vector<int> right = _countPairs(root->right, distance, ans);
        for (int i = 1; i <= distance; ++i)
            for (int j = 1; j <= distance; ++j) {
                if (i + j <= distance) {
                    ans += left[i] * right[j];
                };
            };
        for (int i = 1; i < distance; ++i)
            res[i + 1] = left[i] + right[i];
        return res;
    };
    int countPairs(TreeNode* root, int distance) {
        int ans = 0;
        _countPairs(root, distance, ans);
        return ans;
    }
};