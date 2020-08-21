# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def minDepth(self, root: TreeNode) -> int:
        if not root:
            return 0
        left,right=self.minDepth(root.left),self.minDepth(root.right)
        if left and right:
            return left+1 if left<right else right+1
        return 1+left+right