#include <iostream>
#include "../../Headers/linkList.h"
using namespace std;

void Sort(LinkList &head)
{
    //使用插入排序法
    LinkList rear = head->next;
    head->next = NULL;
    while (rear)
    {
        //pre表示新形成的链表中最后一个比pre的data小的前驱
        LinkList p = head, pre = NULL;
        while (p && p->data <= rear->data)
        {
            pre = p;
            p = p->next;
        }
        //如果pre=NULL说明插入第一个位置
        p = rear;
        rear = rear->next;
        if (pre == NULL)
        {
            p->next = head;
            head = p;
        }
        else
        {
            p->next=pre->next;
            pre->next=p;
        }
    }
}