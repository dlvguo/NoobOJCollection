#include <iostream>
#include <cstring>
using namespace std;

typedef struct node
{
    char data[10];
    node *lchild, *rchild;
} * BTree;
void PrintInExpression(BTree bt)
{
    //中序遍历 操作符出一个() 输出顺序要包含下面的操作数
    //根节点 或者叶节点不需要根号
    if (!bt)
        return;
    //如果为操作符
    if (bt->lchild||bt->rchild)
    {
        cout << '(';
        PrintInExpression(bt->lchild);
        cout<<bt->data;
        PrintInExpression(bt->rchild);
        cout<<")";
    }
    else
    {
        cout<<bt->data;
    }
}