#include <iostream>
#include "../../Headers/BinaryTree.h"
#include <stack>
using namespace std;

//right to left down to up
//切割数组初试1-N
bool JudgeAll(BiTree bt)
{
    if (bt->lchild && bt->rchild)
    {
        bool l=JudgeAll(bt->lchild);
        bool r=JudgeAll(bt->rchild);
        return l&&r;
    }
    return false;
}