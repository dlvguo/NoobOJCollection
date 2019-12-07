#include <iostream>
using namespace std;
//此题类似Hafuman树合并问题每次取最小的俩堆合并即可,为了方便不扩张数组 每次将俩个数组合并后 将数组往前移动1个位置
int MinMerge(int w[],int n){//w[i]表示第i堆石子重量 数组下标1-N
    //总共需要n-1次合并
    int sum=0;
    for (int i = 1; i<n; i++)
    {
        int min1=1,min2=1;//一个第一小一个第二小 
        for (int j = 1; j<=n-i+1; i++)//合并一次长度-1
        {
            if(w[min1]>w[j]){//比最小的小直接更新min1、2 否则再跟第二小比较
                min2=min1;
                min1=j;
            }
            else if(w[min2]>w[j])
                min2=j;
        }
        sum+=w[min1]+w[min2];//min1位置放新合并的元素 min2位置之后往前移动
        w[min1]+=w[min2];
        for (int i = min2+1; i <=n-i+1; i++)
        {
            w[i-1]=w[i];
        }
    }
    return sum;
}