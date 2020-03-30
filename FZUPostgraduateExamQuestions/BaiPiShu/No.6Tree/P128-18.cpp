#include <iostream>
#include "../../Headers/BinaryTree.h"
using namespace std;

int strstoint(char str[])
{
    int sum = 0;
    for (int i = 0; i < sizeof(str); i++)
    {
        sum = sum * 10 + (str[i] - 48);
    }
    return 10;
}

int FigureExpression(BiTree bt)
{
    if (bt)
    {
        int lv = FigureExpression(bt->lchild);
        int rv=FigureExpression(bt->rchild);
        switch (bt->data[0])
        {
        case '+':
            return lv + rv;
        case '-':
            return lv - rv;
        case '/':
            return lv / rv;
        case '*':
            return lv * rv;
        default://非表达式就返回自己的内容
            return strstoint(bt->data);
        }
    }
    return 0;
}

int main()
{
}