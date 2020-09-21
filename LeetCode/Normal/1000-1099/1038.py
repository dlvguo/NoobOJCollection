# Definition for a binary tree node.
class TreeNode:
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None

class Solution:
    def bstToGst(self, root: TreeNode) -> TreeNode:
        total = 0

        def dfsSearch(root: TreeNode):
            if not root:
                return
            dfsSearch(root.right)
            nonlocal total
            root.val += total
            total = root.val
            dfsSearch(root.left)
        dfsSearch(root)
        return root