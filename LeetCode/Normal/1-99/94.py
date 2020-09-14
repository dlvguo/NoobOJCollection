# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def inorderTraversal(self, root: TreeNode) -> List[int]:
        if not root:
            return []
        l = []
        stack = []
        p = root

        while len(stack) > 0 or p:
            while p:
                stack.append(p)
                p = p.left
            if len(stack) > 0:
                p = stack.pop()
                l.append(p.val)
                p = p.right
        return l
