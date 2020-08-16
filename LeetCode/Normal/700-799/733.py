class Solution:
    def floodFill(self, image: List[List[int]], sr: int, sc: int, newColor: int) -> List[List[int]]:
        row, col = len(image), len(image[0])
        p = image[sr][sc]
        if p == newColor:
            return image

        def dfs(x: int, y: int) -> None:
            if x in (-1, row) or y in (-1, col) or image[x][y] != p:
                return 
            image[x][y] = newColor

            for i in (-1,1):
                dfs(x+i, y)
                dfs(x, y+i)

            return image
        
        return dfs(sr, sc)
