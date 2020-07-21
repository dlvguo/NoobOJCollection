# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def generateTrees(self, n: int) -> List[TreeNode]:
        if n < 1: return []     # 特殊情况处理

        def _gen(nums):
            # 结束条件
            if len(nums) == 0: return [None]
            if len(nums) == 1: return [TreeNode(nums[0])]

            # 处理每一层的情况
            ans = []
            for i in range(len(nums)):
                for left in _gen(nums[:i]):
                    for right in _gen(nums[i + 1:]):
                        # 将左右子树和当前节点进行组合
                        ans.append(TreeNode(nums[i], left=left, right=right))
            return ans

        return _gen(list(range(1, n+1)))

