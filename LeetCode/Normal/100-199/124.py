# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    ans = float('-inf')
    def maxPathSum(self, root: TreeNode) -> int:
        def helper(node):
            if not node: return 0
            l = helper(node.left)
            r = helper(node.right)
            self.ans = max(self.ans, max(l,0) + max(r, 0) + node.val)
            return max(l, r, 0) + node.val
        helper(root)
        return self.ans
