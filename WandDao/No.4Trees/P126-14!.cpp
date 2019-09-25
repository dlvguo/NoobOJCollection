#include <iostream>
#include "../../Headers/BinaryTree.h"
#include <queue>
using namespace std;

//层次遍历计算宽度
int FigureWeight(BiTree bt)
{
    if (!bt)
        return 0;
    queue<BiTree> btqueue;
    btqueue.push(bt);
    int left = 1, right = 1, levelcount = 0, maxweight = 1;
    while (!btqueue.empty())
    {
        BiTree bit = btqueue.front();
        btqueue.pop();
        if (bit->lchild)
        {
            btqueue.push(bit->lchild);
            levelcount++;
        }
        if (bit->rchild)
        {
            btqueue.push(bit->rchild);
            levelcount++;
        }
        //防止多来一次 PS
        if(left==right&&!btqueue.empty()){
            left=1;
            right=levelcount;
            maxweight=maxweight<levelcount?levelcount:maxweight;
            levelcount=0;
        }
    }
}