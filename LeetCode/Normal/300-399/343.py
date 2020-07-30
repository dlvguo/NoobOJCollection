class Solution:
    def integerBreak(self, n: int) -> int:
        if n<4:
            return n-1
        elif n==4:
            return 4
        dig=n%3
        if dig==1:
            return (3**(n//3-1))*4
        elif dig==0:
            return 3**(n//3)
        else:
            return dig*(3**(n//3))

        