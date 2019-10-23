#include <iostream>
using namespace std;

typedef struct bitnode
{
    bitnode *lchild, *rchild;
    int data;
} * Bitree;

Bitree FindAncesor(Bitree bt, Bitree p, Bitree q)
{
    //使用俩个栈 s存储长的路径 s1存储短的路径 使用后序遍历
    //point目标节点 pre代表上一个访问的节点 用于判断后序出栈
    Bitree stack[], s1[], point = bt, pre = NULL; //假设栈足够大
    int top = -1, top1 = -1;
    while (point || top != -1)
    {
        //左递归
        while (point && point != p && point != q)
        {
            point = point->lchild;
        }
        //判断是否找到了第一个元素
        if (point)
        {
            //top1==-1说明找到第一个元素 //入栈
            if (top1 == -1)
            {
                for (int i = 0; i <= top; i++)
                {
                    s1[i] = stack[i];
                }
                top1 = top;
            }
            //说明找到了俩个元素
            else{
                for (int i = top1; i >=0; i--)
                {
                    for(int j=top;j>=0;j--)
                        if(s1[i]==stack[j])
                            return s1[i];
                }
            }
        }
        //说明point为空出栈
        else{
            //访问
            point=stack[top];
            //说明右子树访问过了
            if(point->rchild==pre){
                //出栈
                pre=point;
                point=NULL;
                top--;
            }
            else{
                point=point->rchild;
            }
        }
    }
    //可能没找到
    return NULL;
}
