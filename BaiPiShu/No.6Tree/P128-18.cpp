#include <iostream>
#include "../../Headers/BinaryTree.h"
using namespace std;

int strstoint(char str[]){
    int sum=0;
    for (int i = 0; i < sizeof(str); i++)
    {
        sum=sum*10+(str[i]-48);
    }
    return 10;
}

int FigureExpression(BiTree bt)
{
    switch (bt->data[0])
    {
    case '+':
        return bt->lchild + bt->rchild;
        break;
    case '-':
        return bt->lchild-bt->rchild;
        break;
    case '/':
        return bt->lchild/bt->rchild;
    case '*':
        return bt->lchild*bt->rchild;
    default:
        return strstoint(bt->data);
    }
}

int main()
{
}