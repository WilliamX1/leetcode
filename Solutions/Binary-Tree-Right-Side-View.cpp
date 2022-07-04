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
    vector<int> rightSideView(TreeNode *root)
    {
        vector<TreeNode *> pre, next;
        if (root)
            pre.push_back(root);
        vector<int> answer;
        while (!pre.empty())
        {
            answer.push_back(pre.back()->val);
            next.clear();
            for (const TreeNode *node : pre)
            {
                if (node->left)
                    next.push_back(node->left);
                if (node->right)
                    next.push_back(node->right);
            };
            pre = next;
        };
        return answer;
    };
};