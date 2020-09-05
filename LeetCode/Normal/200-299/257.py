# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def binaryTreePaths(self, root: TreeNode) -> List[str]:
        if root is None: return []
        result = []
        subset = [str(root.val)]
        def DFS(root, subset, result):
            if root.left is None and root.right is None:
                result.append(''.join(subset))
                return

            if root.left is not None:
                subset.append('->' + str(root.left.val))
                DFS(root.left, subset, result)
                subset.pop()

            if root.right is not None:
                subset.append('->' + str(root.right.val))
                DFS(root.right, subset, result)
                subset.pop()

        DFS(root, subset, result)

        return result               

