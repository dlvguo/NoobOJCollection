class Solution:
    def reverseWords(self, s: str) -> str:
        ans=""
        temp=""
        for ch in s:
            if ch==' ':
                ans+=(temp[::-1])
                ans+=ch
                temp=""
            else:
                temp+=ch
        if len(temp)>0:
            ans+=temp[::-1]
        return ans