#include <iostream>
#include "../../Headers/linkList.h"
using namespace std;

void Distnict(LinkList p)
{
    LinkList pre = p, rear = p->next;
    while (p)
    {
        if (pre->data == p->data)
        {
            pre->next = p->next;
            delete p;
            p = pre;
        }
        pre = p;
        p = p->next;
    }
}
