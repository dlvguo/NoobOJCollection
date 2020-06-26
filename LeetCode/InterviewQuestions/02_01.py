# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def removeDuplicateNodes(self, head: ListNode) -> ListNode:
        if not head:#如果head里本来就没东西，那就返回head本身
            return head

        r = head #r是head的代言人，负责迭代和更新，head负责原地不动
        record = {head.val} #record负责储存看见过的值。现在已经储存了第一个值

        while r and r.next: #只要r接下来还有东西，就看看下一个东西是不是已经在record当中 
            #这里判断时要同时符合这两个条件，因为如果r已经是None了，判断r.next会报错，所以每次得先判断r

            if r.next.val not in record: #如果下一环的值没被储存过,不用对head作任何修改
                record.add(r.next.val) #在record中添加这个值
                r = r.next #并且让r进入下一环

            else: #如果下一环的值已经见过了
                r.next = r.next.next #直接让r的下一环变为下下环，即把r.next这一环删了
                #这里不用再写"r=r.next"让r进入下一环，原因是r.next已经更改了，要重新进入loop判断现在的r.next(即原来的r.next.next)是否已经遇见过
            
        return head
