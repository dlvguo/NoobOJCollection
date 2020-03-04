#include <bits/stdc++.h>
using namespace std;

int visit[101][101] = {0};
int dir[4][2] = {1, 0, -1, 0, 0, 1, 0, -1};

int orangesRotting(vector<vector<int>> &grid)
{
    int row = grid.size();
    int lie = grid[0].size();
    queue<int> pQueue;
    int step = 0;
    int lanCount = 0, okCount = 0, totalNum = row * lie;
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < lie; j++)
        {
            if (grid[i][j] == 2)
            {
                visit[i][j] = 1;
                pQueue.push(i);
                pQueue.push(j); //烂橘子进队列
                lanCount++;
                okCount++;
            }
            else if (grid[i][j] == 0)
            {
                visit[i][j] = 1;
                okCount++;
            }
        }
    }
    while (okCount != totalNum && !pQueue.empty())
    {
        int num = lanCount;
        lanCount = 0;
        while (num--)
        {
            int x = pQueue.front();
            pQueue.pop();
            int y = pQueue.front();
            pQueue.pop();
            for (int i = 0; i < 4; i++)
            {
                int x1 = x + dir[i][0], y1 = y + dir[i][1];
                if (x1 < 0 || y1 < 0 || x1 >= row || y1 >= lie || visit[x1][y1])
                    continue;
                visit[x1][y1] = 1;
                pQueue.push(x1);
                pQueue.push(y1);
                lanCount++;
                okCount++;
            }
        }
        step++;
    }
    if(okCount!=totalNum)
        return -1;
    return step;
}
