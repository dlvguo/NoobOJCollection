class Solution:
    def calculateMinimumHP(self, dungeon: List[List[int]]) -> int:
        if not dungeon or not dungeon[0]: return 0

        rows, cols = len(dungeon), len(dungeon[0])
        dp = [[0] * cols for _ in range(rows)]
        for i in range(rows - 1, -1, -1):
            for j in range(cols - 1, -1, -1):
                # 转移值
                down, right = float('inf'), float('inf')
                if i < rows - 1:
                    down = dp[i + 1][j] - dungeon[i][j]
                if j < cols - 1:
                    right = dp[i][j + 1] - dungeon[i][j]
                mmin = min(down, right)
                if mmin == float('inf'): mmin = 0   # 边界情况处理

                dp[i][j] = max(1, 1 - dungeon[i][j], mmin)
        return dp[0][0]
