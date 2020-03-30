#include <iostream>
#include "../../Headers/BinaryTree.h"
using namespace std;

int FigureWeight(BiTree bt)
{
    BiTree queue[]; //假设队列足够大
    int front = 0, rear = 1, weight = 0, last = 1, tempweight = 0;
    queue[1] = bt;
    while (front != rear)
    {
        BiTree point = queue[++front];
        tempweight++;
        if (point->lchild)
        {
            queue[++rear] = point->lchild;
        }
        if (point->rchild)
        {
            queue[++rear] = point->rchild;
        }
        if (front == last)
        {
            last=rear;
            weight=tempweight>weight?tempweight:weight;
            tempweight=0;
        }
    }
    return weight;
}