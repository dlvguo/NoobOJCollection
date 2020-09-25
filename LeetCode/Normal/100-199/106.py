# Definition for a binary tree node.
class TreeNode:
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None

class Solution:
    def buildTree(self, inorder: List[int], postorder: List[int]) -> TreeNode:

        def build_tree(in_left, in_right, post_left, post_right):
            if in_left > in_right:
                return
            
            # 后序序列末尾元素就是根节点
            post_root = post_right

            # 构造节点
            root = TreeNode(postorder[post_root])

            # 在中序序列定位根节点位置
            in_root = inorder_map[root.val]    
            
            # size_of_right = in_right - in_root
            # 获取中序序列中左子树的节点数
            size_of_left = in_root - in_left
            
            # root.left = build_tree(in_left, in_root-1, post_left, post_right-size_of_right-1)
            # 递归构建左子树
            root.left = build_tree(in_left, in_root-1, post_left, post_left+size_of_left-1)

            # root.right = build_tree(in_root+1, in_right, post_right-size_of_right, post_right-1)
            # 递归构建右子树
            root.right = build_tree(in_root+1, in_right, post_left+size_of_left, post_root-1)

            return root

        size = len(inorder)
        # 先用字典存储中序序列，元素及其对应的索引位置
        inorder_map = {}

        for i in range(size):
            inorder_map[inorder[i]] = i

        return build_tree(0, size-1, 0, size-1)
