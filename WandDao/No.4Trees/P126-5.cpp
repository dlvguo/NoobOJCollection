#include <iostream>
#include "../../Headers/BinaryTree.h"
#include <stack>
using namespace std;

//链表实现法
void FigureHighByLink(BiTree bt)
{
    //代表一层有多少个节点 遍历完曾节点才到下一层
    int hight=1,left = 1, right = 1, levelcount = 0;
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
        if(btnode->rchild){
            btqueue.push(btnode->rchild);
            levelcount++;
        }
        //说明当前层次遍历完
        if(left==right){
            left=1;
            right=levelcount;
            levelcount=0;
            hight++;
        }
    }
}