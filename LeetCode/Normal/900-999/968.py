# Definition for a binary tree node.
class TreeNode:
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None

class Solution:
    def minCameraCover(self, root: TreeNode) -> int:
        @lru_cache(None)
        def dfs(root, flag): ### flag表示当前节点的状态
            if not root:
                return 1 if flag == 0 else 0
            left, right = root.left, root.right 

            f0 = 1 + dfs(left, 2) + dfs(right, 2)           
            if flag == 0: ### 当前节点装监视器，那么他的子节点都被覆盖
                return f0
            if flag == 1: ### 当前节点没有被覆盖，可以装监视器，也可以让子节点装监视器来被覆盖
                return min([dfs(left, 0) + dfs(right, 1), dfs(left, 1) + dfs(right, 0), f0])
            if flag == 2: ### 当前节点已经被覆盖，可以装监视器，如果当前不装，那么他的子节点都没有被覆盖
                return min(dfs(left, 1) + dfs(right, 1), f0)

        return dfs(root, 1)

