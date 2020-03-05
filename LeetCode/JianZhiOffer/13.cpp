#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool figureNum(int x, int y, int k)
    {
        int sum = 0;
        while (x)
        {
            sum += x % 10;
            x /= 10;
        }
        while (y)
        {
            sum += y % 10;
            y /= 10;
        }
        return sum <= k;
    }
    int dir[4][2] = {1, 0, -1, 0, 0, 1, 0, -1};
    int visit[201][201] = {0};

    struct Pos
    {
        int x, y;
        Pos(int _x, int _y) : x(_x), y(_y) {}
    };

    int movingCount(int m, int n, int k)
    {
        visit[0][0] = 1;
        int sum = 1;
        queue<Pos> pQueue;
        Pos p(0, 0);
        pQueue.push(p);
        while (!pQueue.empty())
        {
            p = pQueue.front();
            pQueue.pop();
            for (int i = 0; i < 4; i++)
            {
                int x = dir[i][0] + p.x, y = dir[i][1] + p.y;
                if (x < 0 || x >= m || y < 0 || y >= n || visit[x][y] || !figureNum(x, y, k))
                    continue;
                visit[x][y] = 1;
                sum++;
                Pos _p(x, y);
                pQueue.push(_p);
            }
        }
        return sum;
    }
};