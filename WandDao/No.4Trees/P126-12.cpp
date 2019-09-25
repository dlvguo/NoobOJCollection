#include <iostream>
#include "../../Headers/BinaryTree.h"
#include <stack>
using namespace std;

//SearchX 采用后序遍历
//bool做标记 防止找到又遍历右边了
bool isFind = false;
void SearchX(BiTree bt, int key)
{
    if (!bt)
        return;
    if (bt->data == key)
    {
        isFind = true;
        return;
    }
    SearchX(bt->lchild);
    if (isFind)
    {
        cout << bt->data;
        return;
    }
    SearchX(bt->rchild);
}