#include <iostream>
using namespace std;
typedef struct BinNode
{
    BinNode *lchild, *rchild;
    int data, lsize;
} * BinTree;

int FindBanch(BinTree bt)
{
    //算层次的时候顺便计算下高度因此 复杂度为O(N)
    //定义个队列假设队列足够大
    BinTree queue[];
    int front =-1,rear=-1,maxlevel=1,heigh=0,level=1;
    queue[++rear]=bt;
    while (front!=rear)
    {
        BinTree p=queue[++front];
        if(p->lchild)
            queue[++rear]=p->lchild;
        if(p->rchild)
            queue[++rear]=p->rchild;
        if(level==front){
            heigh++;
            level=rear;
            maxlevel=maxlevel<rear-front?rear-front:maxlevel;
        }
    }
    return maxlevel*heigh;
}