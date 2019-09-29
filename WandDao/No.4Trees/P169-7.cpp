#include <iostream>
#include "../../Headers/BinaryTree.h"
using namespace std;

//计算层次
int Height(BiTree bt, int key)
{
    if(!bt)
        return 0;
    if (bt->data == key)
        return 1;
    else if (bt->data > key)
    {
        return 1 + Height(bt->rchild);
    }
    else
    {
        return 1 + Height(bt->lchild);
    }
}

int level(BiTree bt,int key){
    int n=0;
    BiTree p=bt;
    if(p){
        while (p->data!=key)
        {
            n++;
            if(p->data<key){
                p=p->rchild;
            }
            else{
                p=p->lchild;
            }
        }
    }
    return n;
}

int main()
{
}