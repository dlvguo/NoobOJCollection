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
    int dir[4][2] = {1, 0, 0, 1};
    int visit[201][201] = {0};

    struct Pos
    {
        int x, y;
        Pos(int _x, int _y) : x(_x), y(_y) {}
    };

    int movingCount(int m, int n, int k)
    {
        visit[0][0] = 1;
        int sum = 0;
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (figureNum(i, j, k))
                    sum++;
                else
                    break;
            }
        }
        return sum;
    }
};