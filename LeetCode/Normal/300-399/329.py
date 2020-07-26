class Solution:
    def longestIncreasingPath(self, matrix: List[List[int]]) -> int:
        if not matrix:
            return 0
        nxt = ((1, 0), (-1, 0), (0, -1), (0, 1))
        old = {}
        matrix = [[float("inf")]+i+[float("inf")] for i in matrix]
        col = len(matrix[0])
        matrix = [[float("inf")]*col]+matrix+[[float("inf")]*col]
        row = len(matrix)

        def maxIncreasingRoute(x: int, y: int) -> int:
            if (x, y) in old:
                return old[(x, y)]
            if x in {0, row-1} or y in {0, col-1}:
                return 0
            old[(x, y)] = 1+max([0]+[maxIncreasingRoute(x+xx, y+yy) for xx, yy in nxt if matrix[x][y] < matrix[x+xx][y+yy]])
            return old[(x, y)]

        return max([maxIncreasingRoute(i, j) for j in range(1, col-1) for i in range(1, row-1)])
