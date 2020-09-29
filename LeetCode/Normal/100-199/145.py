# Definition for a binary tree node.
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right
class Solution:
    def postorderTraversal(self, root: TreeNode) -> List[int]:
        lst = []
        pre = None
        stack = []
        while root or len(stack) > 0:
            if root:
                stack.append(root)
                root = root.left
            else:
                root = stack[-1]
                # 说明访问过子节点回退
                if root.right==None or root.right == pre:
                    stack.pop()
                    pre = root
                    lst.append(root.val)
                    root=None
                else:
                    root = root.right
        return lst