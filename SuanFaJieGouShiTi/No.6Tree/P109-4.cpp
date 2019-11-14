#include <iostream>
#include "../../Headers/BinaryTree.h"
using namespace std;
//求出三个点

//初始化为0
void Figure(BiTree bt, int &n0 = 0, int &n1 = 0, int &n2 = 0)
{
    if (!bt)
        return;
    if (bt->lchild && bt->rchild)
        n2++;
    else if (!bt->lchild && !bt->rchild)
        n0++;
    else
    {
        n1++;
    }
    Figure(bt->lchild, n0, n1, n2);
    Figure(bt->rchild, n0, n1, n2);
}