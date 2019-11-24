#include <iostream>
#include <iostream>
#include <cstring>
using namespace std;
//如何一个工厂有m台服务器 有n个任务需要完成 每台服务器完成任务的时候不同 尽快完成
//局部优先策略 设数组t[]//表示i台服务器当前时间往服务器里面赛 使其尽可能均匀

int FirgureTime(int server[], int m, int n)
{ //server[i]表示第i台完成任务的时候

    int *t = new int[m + 1], max = 0;
    memset(t, 0, sizeof(t));
    for (int i = 1; i <= n; i++)
    {
        int min = server[1] + t[1], index = 1; //找比他小的
        for (int j = 2; j <= m; i++)
        {
            int temp = server[j] + t[j];
            if (min > server[j] + t[j])
            {
                min = temp;
                index = j;
            }
        }
        t[index] = min;
    }
    max=-1;
    for (int i = 1; i <=m; i++)
    {
        max=t[i]>max?t[i]:max;
    }
}