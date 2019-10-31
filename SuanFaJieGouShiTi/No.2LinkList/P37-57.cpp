#include <iostream>
#include "../../Headers/linkList.h"
using namespace std;

void WuLiQuNao(LinkList head, int x)
{
    //在节点的值<=x情况下使用头插法 p表示当前节点，pre表示上一个节点 temp若找到第一个大于x的数为偶数的话用来删除的前继
    LinkList p = head, pre,temp=p;
    if (head->data <= x)
    {
        head = NULL;
        while (p && p->data <= x)
        {
            pre = p;
            p = p->next;
            pre->next = head;
            head = pre;
        }
    }
    pre=temp;
    while (p)
    {
        if(pre->data==p->data||p->data%2){
            pre->next=p->next;
            delete p;
            p=pre;
        }
        pre=p;
        p=p->next;
    }
}
