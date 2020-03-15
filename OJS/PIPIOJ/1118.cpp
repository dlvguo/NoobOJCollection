#include <iostream>
#include <cstring>
using namespace std;

int visit[111];
struct node
{
    int value;
    int x, y;
} map[6666];
int n;
//连接
void Union(int a, int b)
{
    //表示已经在圈内
    if (visit[a] && visit[a] == visit[b])
        return;
    //表示未入圈
    if (visit[a] == 0 && visit[a] == visit[b])
    {
        visit[a] = visit[b] = a;
    }
    //表示连接
    if (visit[a] && visit[b])
    {
        int temp = visit[b];
        for (int i = 1; i <= n; i++)
        {
            if (visit[i] == temp)
                visit[i] = visit[a];
        }
    }
    else if (visit[a])
    {
        visit[b] = visit[a];
    }
    else
    {
        visit[a] = visit[b];
    }
}

void MinValue(int n, int len)
{
    //避免多个元素放入导致出bug
    int sum = 0;
    for (int i = 1; i <= n; i++)
    {
        int index = i, min = -1;
        for (int j = 1; j <= len; j++)
        {
            //都访问过了
            int x = map[j].x, y = map[j].y;
            if (visit[x] && visit[x] == visit[y])
            {
                continue;
            }
            int value = map[j].value;
            if (min == -1 || min > value)
            {
                index = j;
                min = value;
            }
        }
        if (min != -1)
        {
            sum += map[index].value;
            Union(map[index].x, map[index].y);
        }
        else
        {
            break;
        }
        
    }
    cout << sum << endl;
}

//分析错误只能用特斯拉算法
int main()
{
    while (cin >> n, n)
    {
        int a, b, c, d;
        memset(visit, 0, sizeof(visit));
        int len = 0;
        int total = n * (n - 1) / 2;
        for (int i = 1; i <= total; i++)
        {
            cin >> a >> b >> c >> d;
            if (d)
            {
                Union(a, b);
            }
            else
            {
                map[++len].x = a;
                map[len].y = b;
                map[len].value = c;
            }
        }
        MinValue(n, len);
    }
}