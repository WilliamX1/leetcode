#include <stdio.h>
#include <algorithm>
#include <vector>

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
class Solution {
public:
    int minDiffInBST(TreeNode* root) {
        vector<int> arr;
        inorder(root, arr);
        int len = arr.size();
        int res = 2147483647;
        for (int i = 0; i < len - 1; i++)
            res = min(res, arr[i + 1] - arr[i]);
        return res; 
    };
    void inorder(TreeNode* root, vector<int>& arr) {
        if (root->left != nullptr) inorder(root->left, arr);
        arr.push_back(root->val);
        if (root->right != nullptr) inorder(root->right, arr);
        return;
    }
};