#include <iostream>
#include "../../Headers/BinaryTree.h"
using namespace std;

//不用栈输出先序最后一个节点
BiTree Find(BiTree b)
{
    if(b==NULL)
        return b;
    BiTree p = b;
    //只要不是叶节点
    while (p->lchild || p->rchild)
    {
        //如果有右子树 先序最后肯定在右子树
        if (p->rchild)
        {
            p = p->rchild;
            continue;
        }
        //否则就是左子树最右 循环即可
        p=p->lchild;
    }
    return p;
}