#include <iostream>
using namespace std;
//可以这么分析假如一段序列是递增的那么在这段序列中最小值和最大值之差就是这几天的利润 在下个阶段继续找直到计算所有利润
//如 [7 1 5 3 6 4] 可以看成[7] [1 5] [3 6] [4] 利润和为7
int Figure(int price[], int n)
{
    //假设数组下标1-n 于是有
    int low = 1, profit = 0;
    while (low < n)
    {
        int high = low + 1, temp = low;
        while (high <= n && price[high] > price[temp])
        {
            high++;
            temp++;
        }
        if (temp != low)
        {
            profit += price[temp] - price[low];
            low=temp+1;
        }
    }
    return profit;
}
