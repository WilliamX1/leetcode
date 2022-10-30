class Solution
{
  public:
    vector<int> treeQueries(TreeNode *root, vector<int> &queries)
    {
        unordered_map<TreeNode *, int> height; // 每棵子树的高度
        function<int(TreeNode *)> get_height = [&](TreeNode *node) -> int {
            return node ? height[node] = 1 + max(get_height(node->left), get_height(node->right)) : 0;
        };
        get_height(root);

        int res[height.size() + 1]; // 每个节点的答案
        function<void(TreeNode *, int, int)> dfs = [&](TreeNode *node, int depth, int rest_h) {
            if (node == nullptr)
                return;
            ++depth;
            res[node->val] = rest_h;
            dfs(node->left, depth, max(rest_h, depth + height[node->right]));
            dfs(node->right, depth, max(rest_h, depth + height[node->left]));
        };
        dfs(root, -1, 0);

        for (auto &q : queries)
            q = res[q];
        return queries;
    }
};