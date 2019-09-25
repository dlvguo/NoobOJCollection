#include <iostream>
#include "../../Headers/BinaryTree.h"
#include <queue>
using namespace std;

//层次遍历计算宽度
void CreateLink(BiTree bt, BiTree &head, BiTree &pre = NULL)
{
    if (bt->lchild == NULL && bt->rchild == NULL)
    {
        if (pre == NULL)
        {
            head = pre = bt;
        }
        else
        {
            pre->rchild = bt;
            pre = bt;
        }
        return;
    }
    if (bt->lchild)
    {
        CreateLink(bt->lchild, head, pre);
    }
    if (bt->rchild)
    {
        CreateLink(bt->rchild, head, pre);
    }
}