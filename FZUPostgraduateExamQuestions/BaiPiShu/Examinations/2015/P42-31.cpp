#include<iostream>
using namespace std;

//求a[n][m]中 a[i][j]是i行j列中最大值
void Figure(int **a,int n,int m){
    //遍历每行每次从中找最大值 找到与列对比是就输出 考虑每行可能有多个最大值 用个栈表示所有最大值的列id
    int *stack=new int[m+1],top=-1;
    for (int i = 1; i <=n;i++)
    {
        int max=a[i][1];
        stack[++top]=1;
        for (int j = 2; j <=m; j++)
        {
            //如果新的下标更大清空栈
            if(max<a[i][j]){
                stack[0]=j;
                top=1;
            }
            //如果有相等的入栈
            else if(max==a[i][j])
                stack[++top]=j;
        }
        while (top!=-1)
        {
            int lie=stack[top--];
            
            for (int k = 1; k <=n; i++)
            {
                if(a[i][lie]>a[k][lie]){
                    lie=-1;//打个标记循环结束如果为-1 说明不是要的值
                    break;
                }
            }
            if(lie!=-1)
                cout<<a[i][lie]<<endl;
        }
    }
    
}