#include <iostream>
#include "../../Headers/BinaryTree.h"
#include <stack>
using namespace std;

int FigureTwoBranchNum(BiTree bt)
{
    if (bt->lchild && bt->rchild)
    {
        int l = FigureTwoBranchNum(bt->lchild);
        int r = FigureTwoBranchNum(bt->rchild);
        return l + r + 1;
    }
    //代表只有1个分支或者俩个叉都为空
    else
    {
        if (bt->rchild)
            return FigureTwoBranchNum(bt->rchild);
        if (bt->lchild)
            return FigureTwoBranchNum(bt->lchild);
        return 0;
    }
}