
// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
class Solution {
public:
    int getNode(TreeNode* root, int target, TreeNode*& father) {
        if (root->left && root->left->val == target) {
            father = root;
            return 1;
        } else if (root->right && root->right->val == target) {
            father = root;
            return 1;
        } 
        if (root->left) {
            int ans = getNode(root->left, target, father);
            if (father) return ans + 1;
        }
        if (root->right) {
            int ans = getNode(root->right, target, father);
            if (father) return ans + 1;
        } return 0;
    }
    bool isCousins(TreeNode* root, int x, int y) {
        TreeNode* x_father = nullptr, *y_father = nullptr;
        int x_depth = getNode(root, x, x_father); 
        int y_depth = getNode(root, y, y_father);
        return x_father != y_father && x_depth == y_depth;
    }
};

int main()
{
    TreeNode* __4 = new TreeNode(4);
    TreeNode* __5 = new TreeNode(5);
    TreeNode* __3 = new TreeNode(3, nullptr, __5);
    TreeNode* __2 = new TreeNode(2, nullptr, __4);
    TreeNode* __1 = new TreeNode(2, __2, __3);

    Solution S;
    S.isCousins(__1, 5, 4);
    return 0;
}
