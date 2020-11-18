#include <cstdio>
#include <string.h>
#include <vector>
#define MAXN 1505
using namespace std;

vector<int> map[MAXN];
int from[MAXN], used[MAXN];
int n;

int match(int x)
{
    for (int i = 0; i < map[x].size(); ++i)
    {
        if (!used[map[x][i]])
        {
            used[map[x][i]] = 1;
            if (from[map[x][i]] == -1 || match(from[map[x][i]]))
            {
                from[map[x][i]] = x;
                return 1;
            }
        }
    }
    return 0;
}

int main()
{
    int n, u, v, m, sum;
    while (scanf("%d", &n) != EOF)
    {
        memset(from, -1, sizeof(from));
        for (int i = 0; i < MAXN; ++i)
            map[i].clear();
        for (int i = 0; i < n; ++i)
        {
            scanf("%d:(%d)", &u, &m);
            while (m--)
            {
                scanf("%d", &v);
                map[u].push_back(v); //用邻接表
                map[v].push_back(u); //建双向图
            }
        }
        sum = 0;
        for (int i = 0; i < n; ++i)
        {
            memset(used, 0, sizeof(used));
            if (match(i))
                sum++;
        }
        printf("%d\n", sum / 2);
    }
    return 0;
}