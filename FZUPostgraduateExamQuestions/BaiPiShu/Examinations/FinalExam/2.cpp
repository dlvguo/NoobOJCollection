#include <iostream>
using namespace std;
//dfs暴力搜索每个点 直至踩满所有的点 结束
#define N 8
int visit[N + 1][N + 1];                                                                  //表示访问过的结点初始化为0
int path[64][2];                                                                          //表示存放的路径如 path[1][0]表示第一步的x坐标 path[1][1]表示第二步的坐标
int dir[8][2] = {{-1, 2}, {-1, -2}, {1, 2}, {1, -2}, {-2, 1}, {-2, -1}, {2, 1}, {2, -1}}; //表示马走的八个方向

bool dfs(int x, int y, int step)
{
    if (step == 63)
    {
        return true;
    }
    for (int i = 0; i < N; i++)
    {
        int x1 = dir[i][0] + x, y1 = dir[i][1] + y;
        if (x1 < 1 || y1 < 1 || x1 > 8 || y1 > 8 || visit[x1][y1]) //越界问题
            continue;
        visit[x1][y1] = 1;
        path[step+1][0]=x1;
        path[step+1][1]=y1;
        if (dfs(x1, y1, step + 1))
        {
            return true;
        }
        visit[x1][y1] = 0;
    }
    return false;
}

int main()
{
    int x, y;
    cin >> x >> y;
    dfs(x, y, 0);
    path[0][0]=x;
    path[0][1]=y;
    for (int i = 0; i < N*N; i++)
    {
        cout<<path[i][0]<<" "<<path[i][1]<<endl;
    }
}