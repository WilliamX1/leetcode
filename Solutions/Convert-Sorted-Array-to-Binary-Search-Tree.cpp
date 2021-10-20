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
private:
    TreeNode* _sortedArrayToBST(vector<int>& nums, int l, int r) {
        int m = (l + r) >> 1;
        return new TreeNode(nums[m], m > l ? _sortedArrayToBST(nums, l, m - 1) : nullptr, r > m ? _sortedArrayToBST(nums, m + 1, r) : nullptr);
    };
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return nums.size() > 0 ? _sortedArrayToBST(nums, 0, nums.size() - 1) : nullptr;
    };
};