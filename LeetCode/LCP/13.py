from collections import deque
from pprint import pprint


class Solution:

    def minimalSteps(self, maze) -> int:
        def neighbors(i, j):
            for ni, nj in [(i+1, j), (i-1, j), (i, j+1), (i, j-1)]:
                if 0 <= ni < M and 0 <= nj < N:
                    yield ni, nj

        def calc_dist(i, j):
            dist = [[float('inf')]*N for _ in range(M)]
            dist[i][j] = 0
            q = deque([(i, j, 0)])
            while q:
                x, y, d = q.popleft()
                for ni, nj in neighbors(x, y):
                    if maze[ni][nj] != '#' and d + 1 < dist[ni][nj]:
                        dist[ni][nj] = d + 1
                        q.append((ni, nj, d+1))
            return dist

        M, N = len(maze), len(maze[0])
        stones = []
        machines = []
        for i in range(M):
            for j in range(N):
                ch = maze[i][j]
                if ch == 'S':
                    start = (i, j)
                elif ch == 'T':
                    end = (i, j)
                elif ch == 'O':
                    stones.append((i, j))
                elif ch == 'M':
                    machines.append((i, j))

        # regard start as a normal machine
        machines = [start] + machines
        dists = [calc_dist(i, j) for i, j in machines]
        end_dist = calc_dist(*end)

        machine_num = len(machines)

        # shortest path between machines
        edges = [[float('inf')]*machine_num for _ in range(machine_num)]
        for cur, cur_md in enumerate(dists):
            for nxt in range(cur+1, machine_num):
                nxt_md = dists[nxt]
                ci, cj = machines[cur]
                ni, nj = machines[nxt]

                nd = float('inf')
                for si, sj in stones:
                    nd = min(nd, cur_md[si][sj] + nxt_md[si][sj])

                edges[cur][nxt] = edges[nxt][cur] = nd

        state_num = 1 << machine_num
        dp = [[float('inf')] * state_num for _ in range(machine_num)]
        dp[0][1] = 0

        for s in range(1, state_num):
            for cur in range(machine_num):
                if dp[cur][s] == float('inf'):
                    continue
                for nxt in range(machine_num):
                    if s >> nxt & 1:
                        continue
                    dp[nxt][s | 1 << nxt] = min(dp[nxt][s | 1 << nxt],
                                                dp[cur][s] + edges[cur][nxt])

        ans = min(end_dist[i][j] + dp[cur][state_num-1]
                  for cur, (i, j) in enumerate(machines))
        return -1 if ans == float('inf') else ans
