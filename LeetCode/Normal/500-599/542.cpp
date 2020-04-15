#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    struct Pos
    {
        int x, y;
    };

    vector<vector<int>> updateMatrix(vector<vector<int>> &matrix)
    {
        vector<vector<int>> visit(matrix.size(), vector<int>(matrix[0].size(), 0));
        queue<Pos> pq;
        int dir[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
        //多源BFS
        for (int i = 0; i < matrix.size(); i++)
        {
            for (int j = 0; j < matrix[0].size(); j++)
            {
                if (matrix[i][j] == 0)
                {
                    Pos p;
                    p.x = i;
                    p.y = j;
                    pq.push(p);
                    visit[i][j] = 1;
                }
            }
        }
        int step = 0;
        while (pq.size())
        {
            step++;
            int count = pq.size();
            while (count--)
            {
                Pos p = pq.front();
                pq.pop();
                for (int i = 0; i < 4; i++)
                {
                    int x = p.x + dir[i][0], y = p.y + dir[i][1];
                    if (x < 0 || y < 0 || x >= matrix.size() || y >= matrix[0].size() || visit[x][y])
                        continue;
                    matrix[x][y] = step;
                    visit[x][y] = 1;
                    Pos t;
                    t.x = x;
                    t.y = y;
                    pq.push(t);
                }
            }
        }
        return matrix;
    }
};