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
private:
    void pathSum(TreeNode* root, int target, vector<int> cur, vector<vector<int>>& res) {
        cur.push_back(root->val); target -= root->val;
        if (!root->left && !root->right && !target) res.push_back(cur);
        if (root->left) pathSum(root->left, target, cur, res);
        if (root->right) pathSum(root->right, target, cur, res);
        return;
    };
public:
    vector<vector<int>> pathSum(TreeNode* root, int target) {
        vector<int> cur;
        vector<vector<int>> res;
        if (root) pathSum(root, target, cur, res);
        return res;
    }
};