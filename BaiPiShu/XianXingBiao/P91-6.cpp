#include <iostream>
#include "../Headers/linkList.h"
using namespace std;

//
void FindMax(LinkList L)
{
    int max = -1;
    Node *pre = L, *p = L->next, *tpre = L;
    while (p)
    {
        if (max < p->data)
        {
            tpre = pre;
        }
        pre = p;
        p = p->next;
    }
    p = tpre->next;
    if(p){
    tpre->next = p->next;
    delete p;}
}

int main()
{
    freopen("C:/NoobOJCollection/BaiPiShu/XianXingBiao/P91-6.txt", "r", stdin);
    LinkList L;
    InitList(L);
    PrintList(L);
    FindMax(L);
    PrintList(L,false);
}
