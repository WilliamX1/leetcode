# Definition for a binary tree node.
from typing import List

class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right
class Solution:
    def increasingBST(self, root: TreeNode) -> TreeNode:
        ans = []
        if (root): self.recurve(root, ans)
        
        new_root = TreeNode(ans[0])
        cur_root = new_root
        for i in range(1, len(ans)):
            cur_root.right = TreeNode(ans[i])
            cur_root = cur_root.right
        return new_root
        
    def recurve(self, root: TreeNode, ans: List) -> None:
        if (root.left): self.recurve(root.left, ans)
        ans.append(root.val)
        if (root.right): self.recurve(root.right, ans)

T1 = TreeNode(1)
T3 = TreeNode(3)
T2 = TreeNode(2, T1, T3)
S = Solution()
S.increasingBST(T2)

        

 