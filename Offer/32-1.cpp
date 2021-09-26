/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<int> levelOrder(TreeNode* root) {
        deque<TreeNode*> s;
        if (root) s.push_back(root);
        vector<int> ans;
        while (!s.empty()) {
            TreeNode* cur = s.front();
            s.pop_front();
            ans.push_back(cur->val);
            if (cur->left) s.push_back(cur->left);
            if (cur->right) s.push_back(cur->right);
        };
        return ans;
    }
};