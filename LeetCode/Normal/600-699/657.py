class Solution:
    def judgeCircle(self, moves: str) -> bool:
        L=0
        U=0
        for ch in moves:
            if ch=='U':
                U+=1
            elif ch=='D':
                U-=1
            elif ch=='L':
                L+=1
            else:
                L-=1
        return L==0 and U==0