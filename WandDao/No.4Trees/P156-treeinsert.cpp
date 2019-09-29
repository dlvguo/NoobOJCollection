#include <iostream>
#include "../../Headers/BinaryTree.h"
using namespace std;

void Insert(BiTree &bt, int key)
{
    if (!bt)
    {
        bt=new BtNode;
        bt->data=key;
        bt->lchild=bt->rchild=NULL;
    }
    if (bt->data == key)
    {
        return;
    }
    else if (bt->data < key)
    {
        Insert(bt->lchild, key);
    }
    else
    {
        Insert(bt->rchild, key);
    }
}

int main()
{
}