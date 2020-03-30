#include <iostream>
#include "../../Headers/BinaryTree.h"
using namespace std;

//设空树为0
int LevelHight(BiTree &bt)
{
    int height = 0, front = -1, rear = -1, last = 0;
    //假设队列足够大
    BiTree btqueue[], p;
    btqueue[++rear] = bt;
    while (front != rear)
    {
        p = btqueue[++front];
        if (p->lchild)
        {
            btqueue[++rear] = p->lchild;
        }
        if (p->rchild)
        {
            btqueue[++rear] = p->rchild;
        }
        if(front==last){
            last=rear;
            height++;
        }
    }
}

int main()
{
}