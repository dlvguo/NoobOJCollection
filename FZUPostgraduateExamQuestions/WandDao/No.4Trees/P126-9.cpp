#include <iostream>
#include "../../Headers/BinaryTree.h"
#include <stack>
using namespace std;

void Exchange(BiTree bt)
{
    if (!bt)
        return;
    BiTree temp=bt->lchild;
    bt->lchild=bt->rchild;
    bt->lchild=temp;
    Exchange(bt->rchild);
    Exchange(bt->lchild);
}