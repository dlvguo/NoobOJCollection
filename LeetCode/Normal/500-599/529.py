class Solution:
    def updateBoard(self, board: List[List[str]], click: List[int]) -> List[List[str]]:
        x, y = click[0], click[1]
        if board[x][y] == 'M':
            board[x][y] = 'X'
            return board
        dir = [[0, 1], [0, -1], [1, 0], [-1, 0], [1, 1], [1, -1], [-1, 1], [-1, -1]]

        def dfs(x: int, y: int):
            count = 0
            for i in range(8):
                x1 = x + dir[i][0]
                y1 = y + dir[i][1]
                if x1 < 0 or x1 >= len(board) or y1 < 0 or len(board[0]) <= y1 or (
                        board[x1][y1] != 'E' and board[x1][y1] != 'M'):
                    continue

                if board[x1][y1] == 'M':
                    count += 1
            if count > 0:
                board[x][y] = chr(count + 48)
            else:
                board[x][y] = 'B'
                for i in range(8):
                    x1 = x + dir[i][0]
                    y1 = y + dir[i][1]

                    if x1 < 0 or x1 >= len(board) or y1 < 0 or len(board[0]) <= y1 or (
                            board[x1][y1] != 'E' and board[x1][y1] != 'M'):
                        continue

                    dfs(x1, y1)

        dfs(x, y)
        return board