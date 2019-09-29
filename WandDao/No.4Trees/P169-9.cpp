#include <iostream>
#include "../../Headers/BinaryTree.h"
using namespace std;

//
void FindNum(BiTree bt,int &min,int &max)
{
    BiTree p=bt;
    if(!bt){
        return;
    }
    while (p->lchild)
    {
        p=p->lchild;   
    }
    min=p->data;
    p=bt;
    while (p->rchild)
    {
        p=p->rchild;
    }
    max=p->data;
}

int main()
{
}