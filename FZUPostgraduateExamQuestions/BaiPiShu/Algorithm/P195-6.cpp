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
                //找到后从前面开始找 直到找到不同点 则前面一个就是公共祖先 比王道好！！
                for (int i = 1;i<=top1&&i<=top; i++)
                {
                    if(stack[i]!=s1[i])
                        return i-1;
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

//还有一种判断子树法 如果在如果有一个节点等于当前根说明就是公共节点 或者俩个节点分别在左右子树 说明是公共节点
//否则在单一子树就去那边找