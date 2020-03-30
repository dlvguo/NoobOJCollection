#include <iostream>
#include"../../Headers/BinaryTree.h"
#include<queue>
using namespace std;

//数的层次遍历输出就好队列
void LevelPrint(BiTree bt){
    queue<BiTree> q;
    q.push(bt);
    while (!q.empty())
    {
        BiTree p=q.front();
        q.pop();
        cout<<p->data;
        if(p->lchild)
            q.push(p->lchild);
        if(p->rchild)
            q.push(p->rchild);
    }   
}
