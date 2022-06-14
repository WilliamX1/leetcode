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
    bool tryFlip(TreeNode *root, unordered_map<int, int> &index, vector<int> &ans)
    {
        if (root == nullptr)
            return true;
        int left = root->left ? index[root->left->val] : -1;
        int right = root->right ? index[root->right->val] : -1;
        int cur = index[root->val];
        if (left == -1 && right == -1)
            return true;
        if (left != -1 && cur > left || right != -1 && cur > right)
            return false;

        if (left != -1 && right != -1 && left > right)
        {
            TreeNode *tmp = root->left;
            root->left = root->right;
            root->right = tmp;

            ans.push_back(root->val);
        };
        return tryFlip(root->left, index, ans) && tryFlip(root->right, index, ans);
    };
    vector<int> preOrder(TreeNode *root)
    {
        if (root == nullptr)
            return {};
        vector<int> ans;
        vector<int> left = preOrder(root->left), right = preOrder(root->right);
        ans.push_back(root->val);
        ans.insert(ans.end(), left.begin(), left.end());
        ans.insert(ans.end(), right.begin(), right.end());
        return ans;
    };
    vector<int> flipMatchVoyage(TreeNode *root, vector<int> &voyage)
    {
        unordered_map<int, int> index;
        vector<int> ans;

        for (int i = 0; i < voyage.size(); i++)
            index[voyage[i]] = i + 1;
        if (tryFlip(root, index, ans) == false)
            return {-1};
        vector<int> vy = preOrder(root);
        if (vy == voyage)
            return ans;
        else
            return {-1};
    }
};