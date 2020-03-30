#include <iostream>
#include <queue>
using namespace std;

#define NUM 100
//用图存储
typedef struct graph
{
    int edges[NUM][NUM];
    int v[NUM];
    int vnum, edgenum;
} Graph;

Graph g;
int color[NUM];

//DFS染色法
//遍历每个邻接点 使用染色法 若邻接点已经上色且不同则忽略 若上色且相同则非 若未上色换个颜色
bool dfs(int v, int color)
{
    for (int i = 0; i < g.vnum; i++)
    {
        //存在边
        if (g.edges[v][i])
        {
            //未上色且返回false
            if (!color[i] && !dfs(i, -1 * color))
                return false;
            //颜色相同
            if (color[i] == color[v])
                return false;
        }
    }
    return true;
}

//遍历非递归
//使用队列将顶点分为2个集合 若集合的邻接点出现另外个集合的内容则返回错误
bool Judge(Graph G)
{
    int s[];           //表示向量顶点 说明元素属于哪个集合
    queue<int> vqueue; //顶点队列
    int visit[];       //代表访问数组
    for (int i = 0; i < G.vnum; i++)
    {
        //初始化未确定哪个集合
        visit[i] = s[i] = 0;
    }
    int tag = 1;    //集合标记位 1 2
    vqueue.push(0); //顶点0 放入集合
    s[0] = 1;
    while (!vqueue.empty())
    {
        int v = vqueue.front();
        vqueue.pop();
        //准备邻接点符号
        tag = s[v] == 1 ? 2 : 1;
        if (!visit[v])
        {
            visit[v] = 1;
            for (int i = 0; i < g.vnum; i++)
            {
                //边存在
                if (g.edges[v][i])
                {
                    //未加入集合
                    if (!s[i])
                    {
                        s[i] = tag;
                        vqueue.push(i);
                    }
                    //重复
                    else if (s[i] == s[v])
                        return false;
                }
            }
        }
    }
    return true;
}
