#include <iostream>
#include "../../Headers/BinaryTree.h"
using namespace std;

//不放前面是因为有问题
void PrintKey(BiTree bt, int key)
{
    if (!bt)
    {
        return;
    }
    PrintKey(bt->rchild, key);
    if (bt->data >= key)
        cout << bt->data;
    PrintKey(bt->lchild, key);
}

int main()
{
}