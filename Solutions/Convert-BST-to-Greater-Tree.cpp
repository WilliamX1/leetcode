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
    void dfs(TreeNode* root, vector<int>& v) {
        if (root->left) dfs(root->left, v);
        v.push_back(root->val);
        if (root->right) dfs(root->right, v);
        return;
    };
    void put(TreeNode* root, vector<int>& dp, int tot, int& i)
    {
        if (root->left) put(root->left, dp, tot, i);
        root->val = tot - dp[i - 1]; i++;
        if (root->right) put(root->right, dp, tot, i);
        return;
    };
    TreeNode* convertBST(TreeNode* root) {
        vector<int> v;
        if (root) dfs(root, v);
        vector<int> dp; dp.push_back(0);
        int tmp = 0;
        for (auto ele : v)
        {
            tmp += ele;
            dp.push_back(tmp);
        };
        tmp = 1;
        if (root) put(root, dp, accumulate(v.begin(), v.end(), 0), tmp);
        return root;
    }
};