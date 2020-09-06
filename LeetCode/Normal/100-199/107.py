from queue import Queue
from typing import List


class TreeNode:
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None


class Solution:
    def levelOrderBottom(self, root: TreeNode) -> List[List[int]]:
        q = Queue()
        if not root:
            return []
        q.put(root)
        l = []
        while not q.empty():
            count = q.qsize()
            tl = []
            while count > 0:
                count -= 1
                temp = q.get()
                tl.append(temp.val)
                if temp.left:
                    q.put(temp.left)
                if temp.right:
                    q.put(temp.right)
            l.append(tl)
        return l[::-1]
