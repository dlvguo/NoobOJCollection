#include <iostream>
#include <cstring>
using namespace std;
typedef int Element;

typedef struct DNode
{
    Element data;
    DNode *next;
    DNode *prior;
} * DLinkList;

void InitDLinkLst(DLinkList &L, bool isHead = true, bool isLoop = false)
{
    //初始化L
    L = new DNode;
    L->data = -1;
    L->next = NULL;
    L->prior = NULL;
    DNode *rear = L;
    int a;
    while (cin >> a)
    {
        if (!isHead && L->data == -1)
        {
            L->data = a;
            L->next = NULL;
            continue;
        }
        DNode *d = new DNode;
        d->data = a;
        d->next = NULL;
        d->prior = rear;
        rear->next = d;
        rear = rear->next;
    }
    if (isLoop)
    {
        L->prior = rear;
        rear->next = L;
    }
}

void PrintDLinkList(DLinkList D, bool isLoop = false)
{
    DNode *d = D;
    if (isLoop)
    {
        do
        {
            cout << d->data << ' ';
            d = d->next;
        } while (d&&d != D);
    }
    else
        while (d)
        {
            cout << d->data << ' ';
            d = d->next;
        }
    cout << endl;
}
