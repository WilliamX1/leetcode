/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
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
  private:
    TreeNode *_sortedListToBST(vector<int> arr, int l, int r)
    {
        if (l > r)
            return nullptr;
        int m = (l + r) >> 1;
        return new TreeNode(arr[m], _sortedListToBST(arr, l, m - 1), _sortedListToBST(arr, m + 1, r));
    };

  public:
    TreeNode *sortedListToBST(ListNode *head)
    {
        ListNode *ptr = head;
        vector<int> arr;
        while (ptr)
        {
            arr.push_back(ptr->val);
            ptr = ptr->next;
        };
        return _sortedListToBST(arr, 0, arr.size() - 1);
    }
};