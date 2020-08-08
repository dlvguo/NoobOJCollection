# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def recoverTree(self, root: TreeNode) -> None:
        """
        Do not return anything, modify root in-place instead.
        """
        Trees = lambda x: [] if not x else Trees(x.left) + [x] + Trees(x.right)
        a = Trees(root)
        sa = sorted(a, key=lambda x: x.val)
        tmp = [a[i] for i in range(len(a)) if a[i] != sa[i]]
        tmp[0].val, tmp[1].val = tmp[1].val, tmp[0].val
