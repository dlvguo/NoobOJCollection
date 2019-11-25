#include <iostream>
using namespace std;
//先用一个数组C[n]表示这些数的存在 如A中存在2 c[2]表示1 后面依次遍历看下就好
int FindHeroNumber(int a[], int b[],int na,int nb)
{
    int c[];//假设c足够大
    for (int i = 0; i < na; i++)
    {
        c[a[i]]=1;
    }
    int count=0;
    for (int i = 0; i < nb; i++)
    {
       if(c[b[i]])
        count++;
    }
    return count;
}