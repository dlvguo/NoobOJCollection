#include<iostream>
#include"../../Headers/BinaryTree.h"
#include<queue>
using namespace std;

void Create(BiTree A[],BiTree bt){
    queue<BiTree> btqueue;
    btqueue.push(bt);
    int i=1;
    while (!btqueue.empty())
    {
        BiTree p=btqueue.front();
        btqueue.pop();
        A[i++]=p;
        if(p->lchild){
            btqueue.push(p->lchild);
        }
        if(p->rchild){
            btqueue.push(p->rchild);
        }
    }
    
}
