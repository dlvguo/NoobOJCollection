class Solution:
    def countBinarySubstrings(self, s: str) -> int:
        num = 0
        for right in range(1, len(s)):
            left=right-1
            if s[left]==s[right]:
                continue
            num+=1
            left-=1
            right+=1
            while left>=0 and right<len(s) and s[left+1]==s[left] and s[right]==s[right-1]:
                num+=1
                left-=1
                right+=1
        return num
                
