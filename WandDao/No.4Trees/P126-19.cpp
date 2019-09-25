#include <iostream>
#include "../../Headers/BinaryTree.h"
using namespace std;

//非乘高度
int FigureWeight(BiTree bt)
{
    if(bt)
        return 0;
    int data=0;
    if(bt->lchild==NULL&&bt->rchild==NULL)
        data=bt->data;
    return data+FigureWeight(bt->lchild)+FigureWeight(bt->rchild);    
}

//要乘高度的
int FigureWeightByHigh(BiTree bt,int h=1)
{
    if(!bt)
        return 0;
    int data=0;
    if(bt->lchild==NULL&&bt->rchild==NULL)
        data=h*bt->data;
    return data+FigureWeightByHigh(bt->lchild,h+1)+FigureWeightByHigh(bt->rchild,h+1);    
}