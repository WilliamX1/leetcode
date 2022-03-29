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
#include <vector>
#include <stack>

using namespace std;

class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> v;
        int level = 1;

        stack<TreeNode*> cur;
        if (root) cur.push(root);
        while (!cur.empty()) {
            vector<int> vv;
            stack<TreeNode*> next;
            while (!cur.empty()) {
                TreeNode* top = cur.top();
                cur.pop();

                vv.push_back(top->val);

                if (level & 1) {
                    if (top->left) next.push(top->left);
                    if (top->right) next.push(top->right);
                } else {
                    if (top->right) next.push(top->right);
                    if (top->left) next.push(top->left);
                };
            };
            v.push_back(vv);
            cur = next;
            level++;
        };
        return v;
    }
};