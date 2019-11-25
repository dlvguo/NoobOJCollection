#include <iostream>
using namespace std;

//dfs+回溯 暴力求解 因为每个数字只有在这个集合与不在这个集合俩种情况
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