# Definition for a binary tree node.
class TreeNode:
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None

class Solution:
    def findMode(self, root: TreeNode) -> List[int]:
        if not TreeNode:
            return []
        lstv = []
        ans = 0
        maxnum = 0
        last = None

        def midorder(root: TreeNode):
            if not root:
                return
            midorder(root.left)
            nonlocal ans, last, lstv, maxnum
            if root.val == last:
                ans += 1
            else:
                ans = 1
            if ans > maxnum:
                maxnum = ans
                lstv = [root.val]
            elif maxnum == ans:
                lstv.append(root.val)
                
            last = root.val
            midorder(root.right)
        midorder(root)
        return lstv