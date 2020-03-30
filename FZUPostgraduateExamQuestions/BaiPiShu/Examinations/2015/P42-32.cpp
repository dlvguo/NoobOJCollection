#include<iostream>
using namespace std;

void ModSort(int *a,int n){
    //思路设low指针前的数都是模为1 high表示high之后的数模为3 
    //设数组下标为1-n p代表循环下标
    int low=1,high=n,p=1;
    while (p<high)
    {
        int mod=a[p]%3;
        switch (mod)
        {
        case 0://交换low跟p的值
                swap(a[low],a[p]);
                low++;
                p++;
            break;
        case 1:
             p++;
             break;
        case 2:
        default:
             //交换high跟p的值同时此次p的值不变
             swap(a[high],a[p]);
             high--;
            break;
        }
    }
}