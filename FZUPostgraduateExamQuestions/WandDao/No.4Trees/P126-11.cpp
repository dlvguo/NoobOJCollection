#include <iostream>
#include "../../Headers/BinaryTree.h"
#include <stack>
using namespace std;

//删除关键字
void deletekey(BiTree &bt, int key, bool isDelete)
{
    if (!bt)
        return;
    if (key == bt->data || isDelete)
    {
        deletekey(bt->lchild, key, true);
        deletekey(bt->rchild, key, true);
    }
    //释放bt
    if (isDelete)
    {
        delete bt;
        bt=NULL;
    }
}