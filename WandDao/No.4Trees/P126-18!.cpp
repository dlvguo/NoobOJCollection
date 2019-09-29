#include <iostream>
#include "../../Headers/BinaryTree.h"
using namespace std;

//查找中序线索 判断是否叶节点 True 即lchild的lchild false
ThreadTree btnode;
//如果节点有左孩子就是左 右孩子就是右若无看前继 ,看前继左孩子是，没有就继续找 若碰到为空说明没有 叶子点或者根节点
ThreadTree Searchnode(ThreadTree bt, ThreadTree point)
{
    if (!bt)
        return NULL;
    //左子树
    if (bt->lchild && !bt->ltag)
    {
        return bt->lchild;
    }
    //右子树
    else if (bt->rchild && !bt->rtag)
    {
        return bt->rchild;
    }
    else
    {
        while (bt && bt->ltag == 1)
        {
            bt = bt->lchild;
        }
        if (bt->lchild != NULL)
            return bt->lchild;
        return NULL;
    }
}