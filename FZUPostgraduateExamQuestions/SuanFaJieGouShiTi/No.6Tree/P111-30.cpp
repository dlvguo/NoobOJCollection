#include <iostream>
#include "../../Headers/BinaryTree.h"
using namespace std;

void visit(BiTree b);

//不用栈输出先序最后一个节点
void PreVisit(BiTree b)
{
    //用一个新的二叉树节点 存放每次遍历的右孩子 当作头节点使用
    BiTree head=new BiTNode;
    head->rchild=NULL;
    BiTree p=b;
    while (p||head->rchild)
    {
        if(p){
            visit(p);
            if(p->rchild){
                
            }
        }
    }
}