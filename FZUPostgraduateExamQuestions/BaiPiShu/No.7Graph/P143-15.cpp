#include <iostream>
#include "../../Headers/graph.h"
using namespace std;

typedef int Queue;

//因为要求最短时间复杂度 就根据判断即可
//接口判断度
int Du(int w)
{
    return 0;
}

int Dequeue(int q);

void Enqueue(int q, int w);

//进行N轮 每次找到所有的叶节点 直到叶节点<2时候 查询的轮次*2就是最大直径 若m==1 return 2*r m==0 2*r-1
int SearchMax(int n)
{
    Queue q;
    int m = 0;
    int r = 0; //循环轮次
    for (int i = 0; i < n; i++)
    {
        if (Du(i) == 1)
        {
            Enqueue(q, i);
            //叶子树++
            m++;
        }
    }

    while (m >= 2)
    {
        int j = 0; //新一轮叶子数目
        //遍历每个叶节点
        for (int i = 0; i < m; i++)
        {
            int w = Dequeue(q); //表示出队后，与节点v相邻的m节点的度数-1  并返回w节点
            if (Du(w) == 1)
            {
                Enqueue(q, w);
                j++;
            }
        }
        m = j;
        r++;
    }
    return m == 1 ? 2 * r : 2 * r - 1;
}
