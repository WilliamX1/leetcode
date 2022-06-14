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
class Solution
{
  public:
    unordered_map<int, int> m;
    int ans = 0;
    void dfs(TreeNode *root, int targetSum, int count)
    {
        count += root->val;

        auto iter = m.find(count - targetSum);
        if (iter != m.end())
            ans += iter->second;

        m[count]++;
        if (root->left)
            dfs(root->left, targetSum, count);
        if (root->right)
            dfs(root->right, targetSum, count);

        m[count]--;

        return;
    };
    int pathSum(TreeNode *root, int targetSum)
    {
        m[0] = 1;
        if (root)
            dfs(root, targetSum, 0);
        return ans;
    }
};