#include <iostream>
#include "../../Headers/BinaryTree.h"
using namespace std;

//计算相等 先序遍历即可
bool TreeEqual(BiTree bt1, BiTree bt2)
{
    //相等不论是否为空
    if (bt1 == bt2)
    {
        if (!bt1)
            return true;
        else
        {
            return TreeEqual(bt1->lchild, bt2->lchild) && TreeEqual(bt1->rchild, bt2->rchild);
        }
    }
    else
        return false;
}