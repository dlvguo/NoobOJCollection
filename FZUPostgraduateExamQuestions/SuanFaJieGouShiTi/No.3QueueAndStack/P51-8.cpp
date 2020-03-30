#include <iostream>
using namespace std;

//左小右大
//m 为被除数 n为除数
int gcd(int m, int n)
{
    //交换位置
    if (m < n)
        return gcd(n, m);
    //如果余数为0 说明小的那个为最大公因数
    if (m % n)
        return gcd(n, m % n);
    return n;
}

//非递归法
int gcdfdig(int m,int n){
    if(m<n)
        swap(m,n);
    while (m%n)
    {
        int temp=n;
        n=m%n;
        m=n;
    }
    return n;
}
