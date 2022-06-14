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

#include <deque>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution
{
  public:
    void DFS(TreeNode *root, unordered_map<int, int> left, unordered_map<int, int> right)
    {
        root->left = root->right = NULL;
        if (left.count(root->val))
        {
            root->left = new TreeNode(left[root->val]);
            DFS(root->left, left, right);
        };
        if (right.count(root->val))
        {
            root->right = new TreeNode(right[root->val]);
            DFS(root->right, left, right);
        };
        return;
    };
    TreeNode *createBinaryTree(vector<vector<int>> &descriptions)
    {
        unordered_map<int, int> left, right, notFather;

        for (const vector<int> &description : descriptions)
        {
            int parent = description[0], child = description[1], isLeft = description[2];
            notFather[child] = true;

            if (isLeft)
                left[parent] = child;
            else
                right[parent] = child;
        };

        int root = -1;
        for (const vector<int> &description : descriptions)
        {
            int parent = description[0];
            if (!notFather[parent])
            {
                root = parent;
                break;
            };
        };

        TreeNode *ro = new TreeNode(root);
        deque<TreeNode *> d;
        d.push_back(ro);

        while (!d.empty())
        {
            TreeNode *cur = d.front();
            d.pop_front();

            if (left.count(cur->val))
            {
                cur->left = new TreeNode(left[cur->val]);
                d.push_back(cur->left);
            };
            if (right.count(cur->val))
            {
                cur->right = new TreeNode(right[cur->val]);
                d.push_back(cur->right);
            };
        };

        // DFS(ro, left, right);
        return ro;
    }
};