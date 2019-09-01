#include <iostream>
#include "../../Headers/dlinkList.h"
using namespace std;

//输入二进制数创建
void CreatBin(DLinkList &D)
{
    D = new DNode;
    D->data = -1;
    D->next = D;
    D->prior = D;
    DNode *r = D;
    char *str;
    cin >> str;
    while ((*str) != '\0')
    {
        DNode *d = new DNode;
        d->data = ((int)(*str) - 48);
        r->next = d;
        d->prior = r;
        r = d;
        str++;
    }
    r->next=D;
    D->prior=r;
}

void Add1(DLinkList &D)
{
    DNode *r = D->prior;
    r->data++;
    //如果有进位和不等于头节点 一直进1
    while (r != D && r->data == 2)
    {
        r->data = 0;
        r = r->prior;
        r->data++;
    }
    //判断是否要加一个新节点即判断是否走到了头节点
    if (r == D)
    {
        DNode *d = new DNode;
        d->data = 1;
        d->next = D->next;
        d->prior = D;
        D->next->prior = d;
        D->next = d;
    }
}

int main()
{
    //freopen("C:/NoobOJCollection/BaiPiShu/XianXingBiao/P92-5.txt", "r", stdin);
    DLinkList D;
    CreatBin(D);
    PrintDLinkList(D, true);
    Add1(D);
    PrintDLinkList(D, true);
    return 0;
}