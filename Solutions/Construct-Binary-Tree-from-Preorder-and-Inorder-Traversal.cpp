class Solution {
public:
    TreeNode* dfs(vector<int>& preorder, int& mid, vector<int>& inorder, int left, int right, int len) {
        if (left < 0 || left >= len || mid < 0 || mid >= len || right < 0 || right >= len || left > right) return nullptr;
        TreeNode* root = new TreeNode(preorder[mid]);
        for (int i = left; i <= right; i++)
            if (inorder[i] == preorder[mid]) {
                mid++;
                root->left = dfs(preorder, mid, inorder, left, i - 1, len);
                root->right = dfs(preorder, mid, inorder, i + 1, right, len);
                break;
            };
        return root;
    };
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int mid = 0;
        return dfs(preorder, mid, inorder, 0, inorder.size() - 1, preorder.size());
    }
};