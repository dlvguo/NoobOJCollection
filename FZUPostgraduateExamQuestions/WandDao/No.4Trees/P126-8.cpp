#include <iostream>
#include "../../Headers/BinaryTree.h"
#include <stack>
using namespace std;

int FigureTwoBranchNum(BiTree bt)
{
    if (bt == NULL)
        return 0;
    int i = 0;
    //有双叉
    if (bt->lchild && bt->rchild)
    {
        i = 1;
    }
    return i + FigureTwoBranchNum(bt->lchild) + FigureTwoBranchNum(bt->rchild);
}