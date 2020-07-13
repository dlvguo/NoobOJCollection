class Solution:
    def minimumTotal(self, triangle: List[List[int]]) -> int:
        for i in range(1, len(triangle)):
            triangle[i][0] += triangle[i - 1][0]
            for j in range(1, len(triangle[i])-1):
                triangle[i][j] += min(triangle[i - 1][j - 1], triangle[i - 1][j])
            triangle[i][len(triangle[i])-1] += triangle[i - 1][len(triangle[i-1]) - 1]
        return min(triangle[len(triangle)-1])