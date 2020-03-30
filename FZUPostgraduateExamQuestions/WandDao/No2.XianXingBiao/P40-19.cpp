#include <iostream>
#include "../../Headers/linkList.h"
using namespace std;

void release(LinkList A)
{
    Node *p, *pre, *min, *minpre;
    while (A->next != A)
    {
        p = A->next;
        pre = A;
        minpre = A;
        min = A->next;
        while (p != A)
        {
            if (p->data < min->data)
            {
                min = p;
                minpre = pre;
            }
            pre = p;
            p = p->next;
        }
        minpre->next=min->next;
        cout<<min->data<<' ';
        delete min;
    }
    cout<<A->data<<endl;
    delete A;
}

int main()
{
    freopen("C:/NoobOJCollection/WandDao/No2.XianXingBiao/P39-16.txt", "r", stdin);
    LinkList A;
    InitList(A, true);
    Node *a = A;
    while (a->next)
    {
        a = a->next;
    }
    a->next = A;
    release(A);
}
