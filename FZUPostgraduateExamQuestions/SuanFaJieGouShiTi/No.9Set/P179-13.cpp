#include <iostream>
#include "../..//Headers/BinaryTree.h"
using namespace std;

void Search(BiTree b, int key)
{
    BiTree p = b, pre = NULL;
    int tag = 0;
    while (p)
    {
        if (p->data == key)
        {
            p->data++;
            return;
        }
        else
        {
            pre = p;
            if (p->data < key)
            {

                p = p->rchild;
                tag = 1;
            }
            else
            {
                p = p->rchild;
                tag=0;
            }
        }
    }
    BiTree b=new BiTNode;
    b->data=key;b->lchild=b->rchild=NULL;
    if(tag)
    pre->rchild=b;
    else
    {
        pre->lchild=b;
    }   
}