#include <iostream>
#include "../../Headers/BinaryTree.h"
using namespace std;

//假设p在q的左边
//按后序遍历，先找到p的位置，放入辅助栈，再找q的位置进行对比
typedef struct Stack
{
    BiTree bt;
    //tag=0 左子树访问过
    //tag=1 访问过右子树
    int tag = 0;
};

BiTree FindAncesot(BiTree bt, BiTree p, BiTree q)
{
    //假设栈足够大
    Stack s[], s1[], point = bt;
    int top = -1, top1 = -1;
    while (bt || top != -1)
    {
        while (point && point != p && point != q)
        {
            top++;
            s[top].bt=point;
            s[top].tag=0;
            point = point->lchild;
        }
        if (point == p)
        {
            for (int i = 0; i <= top; i++)
            {
                s1[i].bt = s[i].bt;
            }
            top1 = top;
        }
        else if (point == q)
        {
            //找到后开始遍历
            for (int i = 0; i < top; i++)
            {
                for (int j = 0; j < top1; j++)
                {
                    if (s[i].bt==s1[j].bt)
                        {
                            return s[i].bt;
                        }
                }
            }
        }
        //出栈
        while (top!=-1&&s[top].tag)
        {
            top--;
        }
        if (top!=-1)
        {
            point = s[top].bt->rchild;
        }
    }
    return NULL;
}

int main()
{
}