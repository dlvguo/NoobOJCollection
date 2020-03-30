#include <iostream>
#include "../../Headers/linkList.h"
using namespace std;

void del(LinkList &L, int x)
{
    if (L == NULL)
        return;
    if (L->data == x)
    {
        Node *p = L;
        L = L->next;
        delete p;
        del(L, x);
    }
    else
    {
        del(L->next, x);
    }
}

int main()
{
    freopen("C:/NoobOJCollection/WandDao/No2.XianXingBiao/P38-1.txt", "r", stdin);
    LinkList L;
    InitList(L, false);
    del(L, -1);
    PrintList(L, false);
}
