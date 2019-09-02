#include <iostream>
#include "../Headers/linkList.h"
using namespace std;

void AscSort(LinkList &L)
{
    Node *p = L->next, *pre = L;
    while (p)
    {
        //做插入排序 从第一个找到可以插入的位置
        Node *dp = L->next, *dpre = L;
        while (dp && dp->data < p->data && dp != p)
        {
            dpre = dp;
            dp = dp->next;
        }
        if (dp != p)
        {
            pre->next = p->next;
            p->next = dp;
            dpre->next = p;
        }
        else
        {
            pre = p;
        }
        p = pre->next;
    }
}

int main()
{
    freopen("C:/NoobOJCollection/BaiPiShu/XianXingBiao/P91-8.txt", "r", stdin);
    LinkList L;
    InitList(L);
    AscSort(L);
    PrintList(L);
    return 0;
}