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
    unordered_map<TreeNode *, TreeNode *> fa;
    unordered_map<TreeNode *, bool> havebeen;
    TreeNode *start_node = nullptr;
    int ans = 0;
    void getFather(TreeNode *root, int start)
    {
        if (root->left)
        {
            fa[root->left] = root;
            getFather(root->left, start);
        };
        if (root->right)
        {
            fa[root->right] = root;
            getFather(root->right, start);
        };
        if (root->val == start)
            start_node = root;
    };

    void fuse(TreeNode *cur_node, int time)
    {
        ans = max(ans, time);
        havebeen[cur_node] = true;

        if (cur_node->left && !havebeen[cur_node->left])
            fuse(cur_node->left, time + 1);
        if (cur_node->right && !havebeen[cur_node->right])
            fuse(cur_node->right, time + 1);
        if (fa[cur_node] && !havebeen[fa[cur_node]])
            fuse(fa[cur_node], time + 1);
    }

    int amountOfTime(TreeNode *root, int start)
    {
        if (root)
            getFather(root, start);
        if (start_node)
            fuse(start_node, 0);
        return ans;
    }
};