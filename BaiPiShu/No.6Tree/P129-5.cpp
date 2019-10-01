#include <iostream>
#include "../../Headers/BinaryTree.h"
using namespace std;

//假设p在q的左边
//按先序遍历，先找到p的位置，放入辅助栈，再找q的位置进行对比
BiTree FindAncesot(BiTree bt, BiTree p, BiTree q)
{
    //假设栈足够大
    BiTree stack[], s1[], point = bt;
    int top = -1, top1 = -1;
    while (bt || top != -1)
    {
        while (point && point != p&&point!=q)
        {
            stack[++top] = point;
            point = point->lchild;
        }
        if (point == p)
        {
            for (int i = 0; i <= top; i++)
            {
                s1[i] = s[i];
            }
            top1 = top;
        }
        if(point==q){
            //找到后开始遍历
            for (int i = 0; i < top; i++)
            {
                for (int j = 0; j < top1; j++)
                {
                    if(stack[i]==s1[j]){
                        return stack[i];
                    }
                }
                
            }
            
        }
        if(!point){
            point=stack[top--];
            point=point->rchild;
        }
    }
    return NULL;
}

int main()
{
}