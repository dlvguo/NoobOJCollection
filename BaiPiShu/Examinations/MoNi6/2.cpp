#include<iostream>
using namespace std;

//从头开始遍历 若此时数组下标为0 看下一个是否为0是的话置一 然后从n+2开始遍历
bool Plant(int a[],int n,int len){
    int sum=0,i=0;
    while (i<len-1)
    {
        if(a[i]==1){
            i++;
            continue;
        }
        else if(a[i+1]==0){
            //此时种植
            sum++;
            i+=2;
        }
        else {
            i+=3;
        }
    }
    if(i==len-1&&a[i]==0)
        sum++;
    return n==sum;
}