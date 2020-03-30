#include<iostream>
using namespace std;
//找英雄数 相同入栈不同出栈 栈为空的时候下面入栈 最后这个数看看有没有大于总数
int FindHeroNumber(int a[],int n){
    //设数组下标1-n
    int *stack=new int[n+1],top=-1;
    for (int i = 1; i <n; i++)
    {
        if(top==-1){
            stack[++top]=a[i];
        }
        else{
            if(stack[top]==a[i])
                stack[++top]=a[i];
            else
            {
                top--;
            }
        }
    }
    if(top==-1)
        return -1;
    else
    {
        int count=0;
        for(int i=1;i<=n;i++)
            if(stack[top]==a[i])
                count++;
    }
    if(cout>n/2)
        return stack[top];
    return -1;
}