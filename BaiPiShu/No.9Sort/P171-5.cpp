#include <iostream>
using namespace std;

//初始先建立小根堆 之后每次每次取出堆顶

//向下调整 将下的元素下沉 k代表需要调整的目标节点，n顶点数
void AdjustDown(int a[], int k, int n)
{
    int i = k * 2,a[0]=a[k];
    while (i <= n)
    {
        if (i + 1 <= n && a[i] < a[i + 1])
        {
            i++;
        }
        if (a[0] > a[i])
        {
            a[k] = a[i];
            k = i;
            i *= 2;
        }
        else
            break;
    }
    if(i!=k*2)
        a[k]=a[0];
}

//向上调整
void AdjustUp(int a[],int k){
    int i=k/2;
    a[0]=a[k];
    while (i)
    {
        if(a[0]<a[i]){
            a[k]=a[i];
            k=i;
            i/2;
        }
        else
        {
            break;
        }
        
    }
    a[k]=a[0];
}

void MaxBigDui(int a[],int n)
{
    //初始化建立小跟堆
    for (int i = n/2; i >=1; i--)
    {
        AdjustDown(a,i,n);
    }
    //末尾存着最小值 最后逆置
    a[n]=a[1];
    for (int i = 0; i <n; i++)
    {
        //最末尾的数字与第一个最小值交换
        swap(a[n-i]=a[1]);
        //n-1调整
        AdjustUp(a,n-i-1);
    }
    //数组转置
    for (int i = 1; i <n/2; i++)
    {
        swap(a[i],a[n-i+1]);
    }
}