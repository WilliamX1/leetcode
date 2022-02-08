/* 二叉树用数组表示，父节点的下标和子节点的下标的关系 
        0
   1         2
 3   4     5     6
7 8 9 10 11 12 13 14

fathers[x] = (x - 1) / 2;
*/
/* 时间复杂度：O(N), 空间复杂度：O(N) */

#include <unordered_map>

using namespace std;

class Solution{
public:
  void dfs1(TreeNode* cur, TreeNode* fa, unordered_map<TreeNode*, TreeNode*>& father) {
    if (cur == NULL) return;
    father[cur] = fa;
    dfs1(cur->left, cur, father);
    dfs1(cur->right, cur, father);
  };
  bool OK(TreeNode* cur, unordered_map<TreeNode*, TreeNode*>& father) {
    if (cur == NULL || father[cur] == NULL || father[father[cur]] == NULL || (father[father[cur]]->val & 1) != 0) return false;
    else return true;
  };
  int dfs2(TreeNode* root, unordered_map<TreeNode*, TreeNode*>& father) {
    if (root == NULL) return 0;
    return (OK(root, father) ? root->val : 0) + dfs2(root->left, father) + dfs2(root->right, father);
  };
  int sumEvenGrandparent(TreeNode* root) {
    /* 遍历一遍将值存储在数组中 */
    unordered_map<TreeNode*, TreeNode*> father;
    dfs1(root, NULL, father);    
    return dfs2(root, father);
  };
};