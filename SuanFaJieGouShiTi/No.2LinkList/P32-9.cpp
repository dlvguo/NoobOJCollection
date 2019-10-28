#include <iostream>
#include "../../Headers/linkList.h"
using namespace std;

void Merge(LinkList &ha, LinkList hb)
{
    //临时头节点 用于存放最小的元素
    LinkList tempHead = NULL, pa = ha, pb = hb, rear = NULL;
    while (pa && pb)
    {
        if (pa->data == pb->data)
            continue;
        //找到第一个最小元素
        if (tempHead == NULL)
        {
            if (pa->data > pb->data)
            {
                LinkList p = new Node;
                p->data = pb->data;
                tempHead = rear = p;
                pb = pb->next;
                rear->next = NULL;
            }
            else
            {
                tempHead = rear = pa;
                pa = pa->next;
                rear->next = NULL;
            }
        }
        if (pa->data > pb->data)
        {
            LinkList p = new Node;
            p->data = pb->data;
            rear->next=p;
            rear=rear->next;
            pb = pb->next;
            rear->next = NULL;
        }
        else{
            rear->next=pa;
            rear=rear->next;
            pa=pa->next;
            rear->next=NULL;
        }
    }
    ha=tempHead;
}