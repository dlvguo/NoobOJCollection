# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def flatten(self, root: TreeNode) -> None:
        while root:
            if root.left:   #左子树存在的话才进行操作
                sub_left = root.left
                while sub_left.right:   #左子树的右子树找到最深
                    sub_left = sub_left.right
                sub_left.right = root.right #将root的右子树挂到左子树的右子树的最深
                root.right = root.left      #将root的左子树挂到右子树
                root.left = None            #将root左子树清空
            root = root.right               #继续下一个节点的操作

