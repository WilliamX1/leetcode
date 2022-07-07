#include <deque>

using namespace std;

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
    int maxLevelSum(TreeNode *root)
    {
        deque<TreeNode *> dque;
        dque.push_back(root);

        int ans = INT32_MIN, tot = 0, level = -1, index = 1;
        TreeNode *marker = nullptr;
        dque.push_back(marker);

        while (dque.size() > 1)
        {
            TreeNode *node = dque.front();
            dque.pop_front();

            if (node != marker)
            {
                tot += node->val;
                // cout << node->val << ' ' << tot << endl;
                if (node->left)
                    dque.push_back(node->left);
                if (node->right)
                    dque.push_back(node->right);
            }
            else
            {
                if (tot > ans)
                {
                    ans = tot;
                    level = index;
                };
                tot = 0;
                index++;

                dque.push_back(marker);
            };
        };

        level = tot > ans ? index : level;

        return level;
    }
};