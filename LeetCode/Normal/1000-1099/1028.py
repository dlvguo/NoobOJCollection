# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def recoverFromPreorder(self, S: str) -> TreeNode:
        ans = {-1: TreeNode(0)}    
        def addTree(v, p):        
            ans[p] = TreeNode(int(v))
            if not ans[p - 1].left:
                ans[p - 1].left = ans[p]
            else:                  
                ans[p - 1].right = ans[p]
        val, dep = '', 0          
        for c in S:
            if c != '-':
                val += c          
            elif val:              
                addTree(val, dep)   
                val, dep = '', 1    
            else:
                dep += 1            
        addTree(val, dep)        
        return ans[0]