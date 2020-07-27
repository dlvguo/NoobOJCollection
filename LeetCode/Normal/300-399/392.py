class Solution:
    def isSubsequence(self, s: str, t: str) -> bool:
        slen = len(s)
        tlen = len(t)
        i, j = 0,0
        while i < slen and j < tlen:
            if s[i] == t[j]:
                i += 1
            j += 1
        return i == slen