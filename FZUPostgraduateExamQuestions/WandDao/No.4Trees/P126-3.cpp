#include <iostream>
#include "../../Headers/BinaryTree.h"
#include <stack>
using namespace std;

//我那个Tag法也可以
//不过王道更为巧妙 先访问左子树，用一个pre存放上一次访问的变量
//当左子树结束访问后，当前根节点若右子树也访问过则 N->R=Pre 否则访问右子树
void PostOrderByStack(BiTree bt)
{
    stack<BiTree> btstack;
    BiTree r = NULL, p = bt;
    while (p || !btstack.empty())
    {
        if (p)
        {
            btstack.push(p);
            p=p->lchild;
        }
        else{
            //一个POP带元素  和一个getTop获取上限
            p=btstack.top();
            if(p->rchild&&p->rchild!=r){
                p=p->rchild;
                continue;
            }
            visit(p);
            r=p;
            btstack.pop();
        }
    }
}