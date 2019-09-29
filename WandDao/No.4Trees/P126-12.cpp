#include <iostream>
#include "../../Headers/BinaryTree.h"
#include <stack>
using namespace std;

//SearchX 采用后序遍历
//bool做标记 防止找到又遍历右边了
bool isFind = false;
void SearchX(BiTree bt, int key)
{
    if (!bt)
        return;
    if (bt->data == key)
    {
        isFind = true;
        return;
    }
    SearchX(bt->lchild);
    if (isFind)
    {
        cout << bt->data;
        return;
    }
    SearchX(bt->rchild);
}

//王道出栈法 找到直接返回即可
typedef struct
{
    BiTree bt;
    //0表示左子树 1右子树访问
    int tag;
} Stack;

void FindPath(BiTree bt, int key)
{
    //自定义栈
    Stack st[];
    int top - 1;
    BiTree p = bt;
    while (p || top != -1)
    {
        Stack s;
        if (p)
        {
            s.bt = p;
            s.tag = 0;
            st[++top] = s;
            p = p->lchild;
        }
        else
        {
            s = st[top];
            if (s.tag == 0)
            {
                s.tag = 1;
                p = s.bt->rchild;
                continue;
            }
            p = s.bt;
            top--;
            if (p->data == key)
            {
                while (top != -1)
                {
                    cout <<st[top--].bt->data;
                }
            }
        }
    }
}