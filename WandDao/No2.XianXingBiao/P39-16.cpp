#include <iostream>
#include "../../Headers/linkList.h"
using namespace std;

bool isBH(LinkList A, LinkList B)
{
    //暴力法
    Node *a = A, *b;
    while (a)
    {
        Node *p = a; //代表当前a链表位置
        b = B;
        while (p && b)
        {
            if (p->data != b->data)
            {
                break;
            }
            p = p->next;
            b = b->next;
        }
        if (!b)
            return true;
        a=a->next;
    }
    return false;
}

int main()
{
    freopen("C:/NoobOJCollection/WandDao/No2.XianXingBiao/P39-16.txt", "r", stdin);
    LinkList A, B;
    InitList(A, false, 8);
    InitList(B, false, 3);
    cout << isBH(A,B);
}
