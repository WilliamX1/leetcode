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
    bool isSubStructure(TreeNode* A, TreeNode* B, bool flag) {
        if (B == nullptr) return true;
        if (A == nullptr) return false;
        
        bool ans = false;
        if (A->val == B->val) ans |= isSubStructure(A->left, B->left, true) && isSubStructure(A->right, B->right, true);
        if (!flag) ans |= isSubStructure(A->left, B, false) || isSubStructure(A->right, B, false);
        return ans;
    };
public:
    bool isSubStructure(TreeNode* A, TreeNode* B) {
        if (A == nullptr || B == nullptr) return false;
        return isSubStructure(A, B, false);
    };
};