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
class Solution {
public:
    TreeNode* _constructFromPrePost(const vector<int>& preorder, const int& preL, const int& preR, 
                                    const vector<int>& postorder, const int& postL, const int& postR) {
        if (preL > preR) return nullptr;
        else if (preL == preR) return new TreeNode(preorder[preL]);
        else {
            // cout << preL << " " << preR << " " << postL << " " << postR << endl;
            assert(preR - preL == postR - postL && preorder[preL] == postorder[postR]);
            TreeNode* root = new TreeNode(preorder[preL]);
            int preM = preL + 1, postM = postL;
            unordered_map<int, int> count;
            while (preM <= preR && postM < postR) {
                // cout << preM << " " << postM << " " << endl;
                count[preorder[preM]]++;
                count[postorder[postM]]++;

                bool flag = true;
                for (const auto iter : count)
                    if (iter.second & 1)
                        flag = false;
                if (flag) break;
                else {
                    preM++;
                    postM++;
                };
            };
            assert(preM <= preR && postM < postR);
            root->left = _constructFromPrePost(preorder, preL + 1, preM, postorder, postL, postM);
            root->right = _constructFromPrePost(preorder, preM + 1, preR, postorder, postM + 1, postR - 1);
            return root;
        };
    };
    TreeNode* constructFromPrePost(vector<int>& preorder, vector<int>& postorder) {
        return _constructFromPrePost(preorder, 0, postorder.size() - 1, postorder, 0, postorder.size() - 1);
    }
};