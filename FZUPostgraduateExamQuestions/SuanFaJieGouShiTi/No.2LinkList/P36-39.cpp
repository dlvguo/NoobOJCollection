#include <iostream>
using namespace std;

typedef struct SqlList
{
    int len;
    int *data;
};

void MoveMax(SqlList &list,int x)
{
    int low=1,high=list.len;
    //看看是不是跟最末尾相等是就返回
    if(x==list.data[high])
        return;
    while (low<=high)
    {
        int mid=(low+high)/2;
        if(list.data[mid]==x){
            swap(list.data[mid],list.data[mid+1]);
        }
        else if(list.data[mid]<x){
            low=mid+1;
        }
        else
        {
            high=mid-1;
        }
    }
    //此时mid位置为刚好比x的位置 在从位置插入 low指标开始的数向后移动一位
    for(int n=list.len;n>low;n--){
        list.data[n]=list.data[n-1];
    }
    list.data[low]=x;
}