#include <iostream>
#include "../../Headers/array.h"
using namespace std;

//考虑俩种情况 1、2
void MoveK(int a[], int len,int k)
{
    //避免超出len
    k%=len;
    //用一个数组存倒数k个元素 从尾巴开始移动
    int *temp=new int[len];
    for(int i=0;i<k;i++)
        temp[i]=a[len-k+i];
    //后半部分结束后 置换前面的
    for(int j=len-1;j>=k;j--){
        a[j]=a[j-k];
    }
    for(int i=0;i<k;i++){
        a[i]=temp[i];
    }
}

int main()
{
    freopen("C:/NoobOJCollection/BaiPiShu/XianXingBiao/P91-17.txt", "r", stdin);
    int *a = CreatyIntArr(10);
    MoveK(a,10,3);
    PrintArr(a,10);
    return 0;
}