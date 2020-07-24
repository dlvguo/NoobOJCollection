class Solution:
    def divisorGame(self, N: int) -> bool:
        dct = {}

        def dfs(N: int) -> bool:
            if N == 1:
                return False
            if N in dct:
                return dct[N]
            dct[N] = any(not dfs(N-i) for i in range(1, N//2+1) if N%i == 0)
            return dct[N]

        return dfs(N)
