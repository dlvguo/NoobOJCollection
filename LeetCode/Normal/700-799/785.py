class Solution:
    def isBipartite(self, graph: List[List[int]]) -> bool:
        n = len(graph)
        lst = [None]*n
        st = set()

        def dfs(cur: int, up: bool, run: bool) -> bool:
            if run and lst[cur] != None:
                return True
            if cur in st:
                if up == True and lst[cur] == True:
                    return False
                if up == False and lst[cur] == False:
                    return False
                return True
            st.add(cur)
            lst[cur] = not up
            return all([dfs(i, not up, False) for i in graph[cur]])

        for i in range(n):
            st = set()
            if not dfs(i, True, True):
                return False
        return True
