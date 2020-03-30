#include <iostream>
using namespace std;

//????
void AdjustDown(int a[], int k, int n)
{
    //?????????
    int i = k * 2;
    //??
    a[0]=a[k];
    while (i <= n)
    {
        //??????? ??????
        if (i + 1 <= n && a[i + 1] < a[i])
            i++;

        if (a[0] <= a[i])
        {
            break;
        }
        //??????
        a[k]=a[i];
        k=i;
        i*=2;
    }
    a[k]=a[0];
}

//????
void AdjustUp(int a[],int k,int n){
    a[0]=a[k];
    int i=k/2;
    while (i&&a[i]>a[0])
    {
        a[k]=a[i];
        k=i;
        i/=2;
    }
    a[i]=a[0];
}

//???????
//????
void BuildSmallHeap(int a[], int n)
{
    //????????????
    for (int i = n / 2; i >= 1; i--)
    {
        AdjustDown(a, i, n);
    }
}