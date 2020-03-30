#include<iostream>
using namespace std;
//思路：贪心每次取最大面额即可
int Number(int n){
    int num[6]={100,50,20,10,5,1};
    int sum=0;
    for (int i = 0; i <6; i++)
    {
        sum+=n/num[i];
        n=n%num[i];
        if(n==0)
            return sum;
    }
    return sum;
}