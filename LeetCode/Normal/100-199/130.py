class Solution:
    def solve(self, board: List[List[str]]) -> None:
        """
        Do not return anything, modify board in-place instead.
        """
        h = len(board)
        if h <= 1:
            return
        w = len(board[0])
        dir = [[1, 0], [-1, 0], [0, 1], [0, -1]]

        def dfs(b: List[List[str]], x: int, y: int) -> None:
            for i in range(4):
                x1 = x + dir[i][0]
                y1 = y + dir[i][1]
                if x1 < 0 or y1 < 0 or x1 == h or y1 == w or b[x1][y1] == 'V' or b[x1][y1] == 'X':
                    continue
                b[x1][y1] = 'V'
                dfs(b, x1, y1)

        for i in range(w):
            if board[0][i] == "O":
                board[0][i]="V"
                dfs(board, 0, i)
            if board[h - 1][i] == "O":
                board[h-1][i]="V"
                dfs(board, h - 1, i)

        for i in range(1, h - 1):
            if board[i][0] == "O":
                board[i][0]="V"
                dfs(board, i, 0)
            if board[i][w - 1] == "O":
                board[i][w-1]="V"
                dfs(board, i, w - 1)
        for i in range(h):
            for j in range(w):
                if board[i][j] == 'V':
                    board[i][j] = 'O'
                elif board[i][j] == 'O':
                    board[i][j] = 'X'