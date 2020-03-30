#include<iostream>
#include"../../Headers/BinaryTree.h"
#include<stack>
using namespace std;

//中序遍历二叉树 当出栈的时候碰见不小于关键字的输出即可
void PrintOut(BiTree bt,int key){
    BiTree p=bt;
    stack<BiTree> btreequeue;
    while (p||btreequeue.empty())
    {
        if(p){
            btreequeue.push(p);
            p=p->lchild;
        }
        else{
            p=btreequeue.top();
            btreequeue.pop();
            if(p->data>=key){
                cout<<p->data;
            }
            p=p->rchild;
        }
    }
    
}
