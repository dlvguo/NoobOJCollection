#include <iostream>
#include "../../Headers/BinaryTree.h"
using namespace std;

void DividBranches(BiTree &bt, BiTree &newroot = NULL, int key)
{
    if (!bt || newroot)
        return;
    if (bt->data == key)
    {
        newroot = bt;
        bt = NULL;
        return;
    }
    else
    {
        DividBranches(bt->lchild);
        DividBranches(bt->rchild);
    }
}

int main()
{
}