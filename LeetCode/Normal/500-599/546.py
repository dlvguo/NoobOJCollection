class Solution:
    def removeBoxes(self, boxes: List[int]) -> int:
        memo = {}
        # 已知boxes[l]有n个的情况下，boxes[l:r]能获得的最大积分
        def dp(l, r, n):
            nonlocal memo, boxes
            if memo.get((l, r, n)):
                return memo[(l, r, n)]
            
            # 只剩最后一个数字，直接结算
            if l == r - 1:
                return (n + 1) * (n + 1)
            
            # 发现邻居和自己相同，和他加一起结算
            if boxes[l] == boxes[l + 1]:
                return dp(l + 1, r, n + 1)
            
            # 先直接结算，之后再看有没有和自己一样的
            res = (n + 1) * (n + 1) + dp(l + 1, r, 0)

            # 已知下一个和自己不一样，从下下个开始找和自己一样的兄弟
            for l2 in range(l + 2, r):
                # 找到兄弟了
                if boxes[l2] == boxes[l]:
                    res = max(
                        res,
                        # 让自己的下一个到这个兄弟之前结算,
                        # 然后让自己和兄弟加起来结算，
                        # 然后取最大值
                        dp(l + 1, l2, 0) + dp(l2, r, n + 1)
                    )
            memo[(l, r, n)] = res
            return res
        # 初始状态为 已知boxes[0]有0个的情况下， boxes[0:]能获得的最大积分
        return dp(0, len(boxes), 0)

