#include <iostream>
#include "../../Headers/BinaryTree.h"
#include <stack>
using namespace std;

#define K 100
//或者定义全局变量
int FindKNum(BiTree bt, int &n = 1)
{
    if (n == K)
    {
        return bt->data;
    }
    if (n > K)
        return -1;
    int left = FindKNum(bt->lchild, n + 1);
    if (left != -1)
        return left;
    else
        return FindKNum(bt->rchild, n + 1);
}