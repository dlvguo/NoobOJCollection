#include <iostream>
#include "../../Headers/linkList.h"
using namespace std;

Node *FindFirstNode(LinkList a, LinkList b)
{
    //使用a和b放入栈中 假设栈足够大
    LinkList stacka[], stackb[], pa = a, pb = b;
    int topa = -1, topb = -1;
    while (pa && pb)
    {
        stacka[++topa] = pa;
        pa = pa->next;
        stackb[++topb] = pb;
        pb = pb->next;
    }
    while (pa)
    {
        stacka[++topa] = pa;
        pa = pa->next;
    }
    while (pb)
    {
        stackb[++topb] = pb;
        pb = pb->next;
    }
    while (topb!=-1&&topa!=-1&&stacka[topa]==stackb[topb])
    {
        topb--;
        topa--;
    }
    if(stackb[++topb]==stacka[++topa])
        return stacka[topa];
    return NULL;
}