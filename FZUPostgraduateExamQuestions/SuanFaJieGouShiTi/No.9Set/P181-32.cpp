#include <iostream>
using namespace std;
typedef struct BinNode
{
    BinNode *lchild, *rchild;
    int data, lsize;
} * BinTree;

BinTree FindK(BinTree bt, int k)
{
    if (!bt)
        return NULL;
    if (bt->lsize==k)
    {
        return bt;
    }
    else if(bt->lsize<k)
        return (bt->rchild,k-bt->lsize);
    else
        return (bt->lchild,k);
}