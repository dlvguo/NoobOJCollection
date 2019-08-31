#include <iostream>
#include "../../Headers/linkList.h"
using namespace std;
void Reverse(LinkList &L);
//二进制创建 头插法
void CreatBin(LinkList &L, int n)
{
    L = new Node;
    L->data = -1;
    L->next = NULL;
    while (n)
    {
        int dig = n % 2;
        n /= 2;
        Node *node = new Node;
        node->data = dig;
        node->next = L->next;
        L->next = node;
    }
}

void Add1(LinkList L)
{
    //倒置一遍+1 然后再倒一遍？
    Reverse(L);
    //代表最后一个指针
    Node *p = L->next;
    p->data++;
    while (p && p->data == 2)
    {
        p->data = 0;
        if (p->next != NULL)
            p->next->data++;
        else
        {
            Node *n = new Node;
            n->data = 1;
            n->next = NULL;
            p->next = n;
            break;
        }
        p=p->next;
    }
    Reverse(L);
}

//转置LinkList
void Reverse(LinkList &L)
{
    Node *p = L->next, *temp;
    L->next = NULL;
    while (p)
    {
        temp = p;
        p = p->next;
        temp->next = L->next;
        L->next = temp;
    }
}

int main()
{
    freopen("C:/NoobOJCollection/BaiPiShu/XianXingBiao/P92-4.txt", "r", stdin);
    LinkList L;
    CreatBin(L, 3);
    PrintList(L);
    Add1(L);
    PrintList(L);
    return 0;
}