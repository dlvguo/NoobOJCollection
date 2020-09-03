class Solution:
    def solveNQueens(self, n: int) -> List[List[str]]:
        # 按行枚举
        col, diag, reverse_diag = [0] * n, [0] * 2 * n, [0] * 2 * n
        ret = []
        grid = [['.'] * n for _ in range(n)]
        def dfs(u:int):
            # 终点返回
            if u == n:
                ret.append(["".join(grid[i]) for i in range(n)])
                return
            for i in range(n):
                if not col[i] and not diag[u + i] and not reverse_diag[n - u + i]:
                    grid[u][i] = 'Q'
                    col[i], diag[u + i], reverse_diag[n - u + i] = 1, 1, 1
                    dfs(u + 1)
                    grid[u][i] = '.'
                    col[i], diag[u + i], reverse_diag[n - u + i] = 0, 0, 0
        dfs(0)
        return ret

