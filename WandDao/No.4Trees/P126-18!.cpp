#include <iostream>
#include "../../Headers/BinaryTree.h"
using namespace std;

//查找中序线索 判断是否叶节点 True 即lchild的lchild false
ThreadTree btnode;
void Searchnode(ThreadTree bt, ThreadTree point)
{
    if (!bt)
        return NULL;
    //相等不论是否为空
    if (bt == point)
    {
        //左子树
        if (bt->rchild != NULL&&!bt->rtag)
        {
            btnode = *bt->rchild;
        }
        //右子树
        else if (bt->lchild != NULL&&!bt->ltag)
        {
            btnode = *bt->lchild;
        }
        else //如果是叶子节点 即为父节点的左子树节点就为前继 且
        {
            bt=bt->lchild;
            if(bt->ltag)
            btnode=*bt->lchild;
            else{
                btnode=NULL;
            }
        }
        return;
    }
    else
    {
        Searchnode(bt->lchild, point);
        Searchnode(bt->rchild, point);
    }
}