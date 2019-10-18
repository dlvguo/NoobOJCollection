#include <iostream>
using namespace std;

void Divid(int a[], int len)
{
    //假设数组下标从1-n
    int low = 1, high = len;
    //利用快排思想 先从右边找到第一个奇数 再从左边找到第一个偶数 若low<high交换继续 否则完成
    while (low < high)
    {
        while (low<high&&a[high]%2==0)
        {
            high--;
        }
        while (low<high&&a[low]%2)
        {
            low++;
        }
        if(low<high){
            int temp=a[low];
            a[low]=a[high];
            a[high]=temp;
        }
    }
}