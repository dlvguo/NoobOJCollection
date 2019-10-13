#include <iostream>
#include <cstring>
using namespace std;

#define N 999
void FindTwoMax(int *a,int &min,int &max){
    //每次取出俩个元素 然后先对比 小的跟min比 大的跟max比
    int min=a[0],max=a[0],low=1,high=N-1;
    while (low<=high)
    {
        int min1,max1;
        if(a[low]<a[high]){
            min1=a[low];
            max1=a[high];
        }
        else{
            min1=a[high];
            max1=a[low];
        }
        min=min>min1?min1:min;
        max=max<max1?max1:max;
        low++;
        high--;
    }
}