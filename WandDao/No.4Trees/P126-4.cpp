#include <iostream>
#include "../../Headers/BinaryTree.h"
#include <stack>
using namespace std;

//right to left down to up
//正常方式倒叙
void ReverseLevelOrder(BiTree bt)
{
    queue<BiTree> btqueue;
    stack<BiTree> btstack;
    btqueue.push(bt);
    while (!btqueue.empty())
    {
        BiTree btnode = btqueue.front;
        btstack.push(btnode);
        btqueue.pop();
        if (btnode->lchild)
            btqueue.push(btnode->lchild);
        if (btnode->rchild)
            btqueue.push(btnode->rchild);
    }
    while (!btstack.empty()){
        BiTree btnode=btstack.top();
        btstack.pop();
        visit(btnode);
    }
}