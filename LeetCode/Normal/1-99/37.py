class Solution:
    def solveSudoku(self, board: List[List[str]]) -> None:

        nums = {"1", "2", "3", "4", "5", "6", "7", "8", "9"}
        row = [set() for _ in range(9)]
        col = [set() for _ in range(9)]
        palace = [[set() for _ in range(3)] for _ in range(3)]  # 3*3
        blank = []

        # 初始化，按照行、列、宫 分别存入哈希表
        for i in range(9):
            for j in range(9):
                ch = board[i][j]
                if ch == ".":
                    blank.append((i, j))
                else:
                    row[i].add(ch)
                    col[j].add(ch)
                    palace[i//3][j//3].add(ch)

        def dfs(n):
            if n == len(blank):
                return True
            i, j = blank[n]
            rst = nums - row[i] - col[j] - palace[i//3][j//3]  # 剩余的数字
            ### rst = nums - (row[i] | col[j] | palace[i//3][j//3])  
            if not rst:
                return False
            for num in rst:
                board[i][j] = num
                row[i].add(num)
                col[j].add(num)
                palace[i//3][j//3].add(num)
                if dfs(n+1):
                    return True
                row[i].remove(num)
                col[j].remove(num)
                palace[i//3][j//3].remove(num)

        dfs(0)
