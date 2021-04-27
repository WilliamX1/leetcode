# Definition for a binary tree node.
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right
class Solution:
    def add_while_search(self, root: TreeNode, low: int, high: int) -> int:
        if not root: return 0
        
        if root.val < low: return self.add_while_search(root.right, low, high)
        elif root.val > high: return self.add_while_search(root.left, low, high)
        else:
            ans = root.val
            ans += self.add_while_search(root.left, low, high)
            ans += self.add_while_search(root.right, low, high)
            return ans
    def rangeSumBST(self, root: TreeNode, low: int, high: int) -> int:
        return self.add_while_search(root, low, high)
    
S = Solution()
node0 = TreeNode(0)
node2 = TreeNode(2)
node1 = TreeNode(1, node0, node2)
print(S.rangeSumBST(node1, 0, 2))