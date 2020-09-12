# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def averageOfLevels(self, root: TreeNode) -> List[float]:
        # 题目数组非空，
        # if not root:
        #     return []

        # 返回结果
        res = []

        from collections import deque
        # 定义队列
        queue = deque()
        # 将根节点入队
        queue.append(root)
        # 队列不为空，表达式二叉树还有节点，循环遍历
        while queue:
            # 先标记每层的节点数
            size = len(queue)
            # 定义变量，记录每次节点值
            total = 0
            # 这里开始遍历当前层的节点
            for _ in range(size):
                # 出队
                node = queue.popleft()
                # 先将当前节点的值存储
                total += node.val
                # 节点的左右节点非空时，入队
                if node.left:
                    queue.append(node.left)
                if node.right:
                    queue.append(node.right)
            # 添加每层的节点值均值
            res.append(total/size)
        return res

