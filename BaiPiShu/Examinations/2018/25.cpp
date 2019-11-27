#include <iostream>
#include<math.h>
using namespace std;

//dfs+回溯 暴力求解 因为每个数字只有在这个集合与不在这个集合俩种情况 我这个也可以了 看看优化版本
//数组下标为1-n
int stack[], top = -1, n, m; // 一个栈存放路径  stack[i]表示 前面所有数的总和 如s[4]的value=s[1]+s[2]+s[3]方便迭代
void dfs(int a[], int index = 1)
{
    if (index > n)
        return;
    //栈为空
    if (top = -1 )
    {
        if(a[i]>m)
        dfs(index + 1);
        else
        {
            //选择放入或不放入
            stack[++top]=a[index];
            dfs(index+1);
            //回溯之后不放入
            --top;
            dfs(index+1);
        }   
    }
    //栈不为空情况 先判断下栈顶元素是否已经为w如果是的话表示ok
    else
    {
        if(stack[top]==m){
            //TODO 输出路径 返回上一层继续迭代
            return;
        }
        if(stack[top]+a[index]>m){//直接不放入
            dfs(index+1);
        }
        else{
            //选择放入或不放入
            stack[++top]=a[index];
            dfs(index+1);
            //回溯之后不放入
            --top;
            dfs(index+1);
        }
    }
}

//还有一种 假设数组都是a[10]里面有如果 1 表示 a[1]放入 11表示a[2][1]放入 是不是跟二进制数一样于是乎这所有数字的一个数代表2
//总共需要pow(2,n-1)的大小
//用pow函数计算
int FigureTotal(int a[],int n,int m){
    int N=pow(2,n-1);
    //遍历每种情况
    int stack[],top=-1;
    for (int i = 1; i <=N; i++)
    {
        //下标从a[1]开始 
        int index=1,sum=0,num=i;
        //同时用个队列存放数组所有选取的index
        top=-1;
        while (num)
        {
            if(num%2)//说明此时可以放入
            {
                sum+=a[index];
                stack[++top]=index;
            }
            index++;
            num/=2;
        }
        if(sum==m){
            while (top!=-1)
            {
                cout<<stack[top--];
            }
        }
    }
}