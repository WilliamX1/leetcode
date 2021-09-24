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
private:
    vector<int> v;
    void kthLargest(TreeNode* root) {
        if (root->right) kthLargest(root->right);
        v.push_back(root->val);
        if (root->left) kthLargest(root->left);
    }
public:
    int kthLargest(TreeNode* root, int k) {
        if (root) kthLargest(root);
        return v[k - 1];
    }
};