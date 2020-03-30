#include <iostream>
#include "../../Headers/BinaryTree.h"
#include <queue>
using namespace std;

//right to left down to up
//切割数组初试1-N
bool JudgeAll(BiTree bt)
{
    if (bt->lchild && bt->rchild)
    {
        bool l = JudgeAll(bt->lchild);
        bool r = JudgeAll(bt->rchild);
        return l && r;
    }
    //全为空为true
    return !bt->rchild && !bt->lchild;
}

//队列层次遍历 王道复杂了
bool JudgeAllTree(BiTree bt)
{
    queue<BiTree> btqueue;
    btqueue.push(bt);
    while (!btqueue.empty())
    {
        BiTree p = btqueue.front();
        btqueue.pop();
        if (p->lchild && p->rchild)
        {
            btqueue.push(p->lchild);
            btqueue.push(p->rchild);
        }
        else
        {
            if (bt->lchild || bt->rchild)
            {
                return false;
            }
        }
    }
    return ture;
}
