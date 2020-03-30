#include <iostream>
#include "../../Headers/BinaryTree.h"
#include <stack>
using namespace std;

//链表实现法
void FigureHighByLink(BiTree bt)
{
    //代表一层有多少个节点 遍历完曾节点才到下一层
    int hight = 1, left = 1, right = 1, levelcount = 0;
    queue<BiTree> btqueue;
    btqueue(bt);
    while (!btqueue.empty())
    {
        BiTree btnode = btqueue.front();
        btqueue.pop();
        if (btnode->lchild)
        {
            btqueue.push(btnode->lchild);
            levelcount++;
        }
        if (btnode->rchild)
        {
            btqueue.push(btnode->rchild);
            levelcount++;
        }
        //说明当前层次遍历完 防止最后一层多搞一次
        if (left == right && !btqueue.empty())
        {
            left = 1;
            right = levelcount;
            levelcount = 0;
            hight++;
        }
    }
}

//数组实现法
int FigureHighByArr(BiTree bt)
{
    BiTree barr[999];
    int front = -1, rear = -1, last = 0, high = 0;
    barr[++rear] = bt;
    while (front != rear)
    {
        BiTree p = barr[++front];
        if (p->lchild != NULL)
            barr[++rear] = p->lchild;
        if (p->rchild != NULL)
            barr[++rear] = p->rchild;
        if(last==front){
            high++;
            last=rear;
        }
    }
    return high;
}

//底层计算
int DfsFigure(BiTree bt)
{
    if (bt == NULL)
        return 0;
    int lheigh = DfsFigure(bt->lchild);
    int rheigh = DfsFigure(bt->rchild);
    //哪边分支大就用哪变的高度
    return lheigh > rheigh ? lheigh + 1 : rheigh + 1;
}