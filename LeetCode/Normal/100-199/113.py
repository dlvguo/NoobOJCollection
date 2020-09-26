# Definition for a binary tree node.
from typing import List


class TreeNode:
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None


class Solution:
    def pathSum(self, root: TreeNode, sum: int) -> List[List[int]]:
        self.paths = []
        self.temp = []

        def dfs(ans: int, root: TreeNode):
            if not root:
                return
            ans += root.val
            self.temp.append(root.val)
            if ans == sum:
                if not root.right and not root.left:
                    self.paths.append(self.temp[:])
                    self.temp.pop()
                    return
            dfs(ans, root.left)
            dfs(ans, root.right)
            self.temp.pop()

        dfs(0, root)
        return self.paths
