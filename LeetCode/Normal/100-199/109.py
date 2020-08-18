# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def sortedListToBST(self, head: ListNode) -> TreeNode:
        len_ = 0
        temp = head
        while temp:
            len_ += 1
            temp = temp.next
        def BuildTree(left,right):
            nonlocal head
            if left > right:
                return
            mid = left + (right - left) // 2
            root = TreeNode()
            root.left = BuildTree(left,mid - 1)
            # 中序遍历
            root.val = head.val
            head = head.next
            root.right = BuildTree(mid + 1,right)
            return root
        return BuildTree(0, len_ - 1)


