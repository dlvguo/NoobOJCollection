class Solution:
    def translateNum(self, num: int) -> int:
        s, a, b = str(num), 1, 1
        for i in range(1, len(s)):
            a, b = b, ((a+b) if 10 <= int(s[i - 1:i + 1]) <= 25 else b)
        return b
