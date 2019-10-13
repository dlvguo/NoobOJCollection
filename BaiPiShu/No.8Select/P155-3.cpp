#include <iostream>
#include "../../Headers/BinaryTree.h"
#include <stack>
using namespace std;

//设二叉排序树左小右大排列
int FigureHalf(BiTree bt)
{
    BiTree p = bt;
    int min, max;
    //找最小值
    while (p->lchild)
    {
        p = p->lchild;
    }
    min = p->data;
    p = bt;
    //找最大值
    while (p->rchild)
    {
        p = p->rchild;
    }
    int half = (min + max) / 2;
    //碰见一个节点若等于half 返回0 若找到一个左小右大 比差额
    p = bt;
    while (bt)
    {
        if (bt->data == half)
            return 0;
        //遍历左子 half比当前节点小
        if (bt->data > half)
        {
            //如果bt无左子树说明差额就在这
            if (!bt->lchild)
            {
                return bt->data - half;
            }
            //如果左子树比half小 差额在俩者之间 //否则继续 右子树一样
            if(bt->lchild->data<half)
                return bt->data-half>half-bt->lchild->data?half-bt->lchild->data:bt->data-half;
            bt=bt->lchild;
            continue;
        }
         if (!bt->lchild)
            {
                return  half-bt->data;
            }
            //如果左子树比half小 差额在俩者之间 //否则继续 右子树一样
            if(bt->rchild->data>half)
                return bt->rchild->data-half>half-bt->data?half-bt->data:bt->rchild->data-half;
            bt=bt->rchild;
    }
}
