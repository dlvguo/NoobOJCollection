#include <iostream>
using namespace std;

int MaxValue(int group[][], int n, int desk[], int m)
{
    //group[1][0]表示团队1的人数 group[1][1]表示团队1的消费金额 按金额消费从大到小排列
    //desk按桌子数从小到大排列 这样能保证最大金额的团队坐最小人数的桌子 尽可能的满足多的人就坐
    for (int i = 1; i < n; i++)
    {
        for (int j = 1; j <= n - i; j++)
            if (group[j][1] < group[j + 1][1])
            {
                swap(group[j][0], group[j + 1][0]);
                swap(group[j][1], group[j + 1][1]);
            }
    }
    for (int i = 1; i < m; i++)
    {
        for (int j = 1; j <= m - i; j++)
            if (desk[j] > desk[j + 1])
            {
                swap(desk[j], desk[j + 1]);
            }
    }
    int sum=0;
    //尽量把所有桌子安排上 如果count==m说明所有桌子安排好了 同时desk[1]==-1表示此桌子已经坐人了
    for (int i = 1, count = 0; i <= n && count != m; i++) //如果桌子安排完了 结束
    {
        for (int j = 1; j <= ; i++)
        {
            //因为desk从小到大排序 于是只要碰见能放入顾客的便是最小的容量桌子
            if(group[i][0]<=desk[j]&&desk[j]!=-1){
                sum+=group[i][1];
                desk[j]=-1;
                count++;
            }
        }
    }
    return sum;
}
