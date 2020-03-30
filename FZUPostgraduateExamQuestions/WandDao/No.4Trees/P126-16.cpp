#include <iostream>
#include "../../Headers/BinaryTree.h"
using namespace std;

//设置一个头指针
BiTree head, pre = NULL;
void CreateLink(BiTree bt)
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