#include<iostream>
using namespace std;
void HalfInsert(int a[],int n){
    for (int i = 2; i <= n; i++)
    {
        int low=1,high=i-1;
        while (low<=high)
        {
            int mid=(low+high)/2;
            if(a[mid]>a[i])
                high=mid-1;
            else
                low=mid+1;
        }
        //此时high+1的位置为目标存放的节点
        //先后移
        a[0]=a[i];
        high++;
        for (int j =i ; i > high; i++)
        {
            a[j]=a[j-1];
        }
        a[high]=a[0];
    }
}