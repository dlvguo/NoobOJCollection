class Solution:
    def countSubstrings(self, s: str) -> int:
        ans = len(s)

        def figureCount(s: str, left: int, right: int) -> int:
            count = 0
            while left >= 0 and right < len(s) and s[left] == s[right]:
                count += 1
                left -= 1
                right += 1
            return count

        for i in range(len(s) - 1):
            ans += figureCount(s, i - 1, i + 1)
            ans += figureCount(s, i, i + 1)

        return ans