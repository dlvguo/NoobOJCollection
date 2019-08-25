#include <iostream>
#include "../Headers/linkList.h"
using namespace std;

void reverse(LinkList &L)
{
    Node *p = L->next, *pr = NULL;
    L->next = NULL;
    while (p)
    {
        pr = p;
        p = p->next;
        pr->next = L->next;
        L->next = pr;
    }
}

int main()
{
    freopen("C:/NoobOJCollection/BaiPiShu/XianXingBiao/P91-7.txt", "r", stdin);
    LinkList L;
    InitList(L);
    reverse(L);
    PrintList(L);
    return 0;
}