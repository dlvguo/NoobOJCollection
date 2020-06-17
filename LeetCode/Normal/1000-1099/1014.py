class Solution:
    def maxScoreSightseeingPair(self, A: List[int]) -> int:
        left, res = A[0], -1
        for j in range(1, len(A)):
            res = max(res, left + A[j] - j)
            left = max(left, A[j] + j)
        return res