#include <iostream>
#include "../../Headers/linkList.h"
using namespace std;

void Divide(LinkList &A, LinkList &B, LinkList &C)
{
    //pb代表b链表中最末尾那个 c代表c链中最末尾那个初始为NULL
    LinkList pa = A->next, pb = NULL, pc = NULL;
    while (pa)
    {
        //插入A中
        if (pa > 0)
        {
            if (pb = NULL)
            {
                B = pb = pa;
                pa = pa->next;
                pb->next = NULL;
            }
            else
            {
                pb->next = pa;
                pa = pa->next;
                pb = pb->next;
                pb->next = NULL;
            }
        }
        if (pa < 0)
        {
            if (pc = NULL)
            {
                C = pc = pa;
                pa = pa->next;
                pb->next = NULL;
            }
            else
            {
                pc->next = pa;
                pa = pa->next;
                pb = pb->next;
                pb->next = NULL;
            }
        }
    }
}