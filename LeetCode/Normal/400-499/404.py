# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def sumOfLeftLeaves(self, root: TreeNode) -> int:
        number = 0

        def dfs(root: TreeNode, flag=0):
            if not root:
                return
            if not root.left and not root.right and flag:
                nonlocal number
                number += root.val
                return
            dfs(root.left, 1)
            dfs(root.right, 0)

        dfs(root, 0)
        return number