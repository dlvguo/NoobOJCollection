# Definition for a binary tree node.
class TreeNode:
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None

class Solution:
    def lowestCommonAncestor(self, root: 'TreeNode', p: 'TreeNode', q: 'TreeNode') -> 'TreeNode':
        def dfs(root: TreeNode, p: 'TreeNode', q: 'TreeNode') -> TreeNode:
            if root.val > p.val and root.val > q.val:
                return dfs(root.left, p, q)
            elif root.val<p.val and root.val<q.val:
                return dfs(root.right, p, q)
            else:
                return root
        if p.val < q.val:
            return dfs(root, p, q)
        return dfs(root, q, p)
