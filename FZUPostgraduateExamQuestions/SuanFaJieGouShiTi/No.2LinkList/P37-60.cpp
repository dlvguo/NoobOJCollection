#include <iostream>
#include <cstring>
using namespace std;

typedef struct dnode
{
    dnode *prior, *next;
    int data;
} * DLinkList;
;

void Reverse(DLinkList &head)
{
    //假设head不带头节点
    DLinkList x = head;
    //先让头节点变成head->next
    head = head->next;
    head->prior = x->prior;
    x->prior->next = head;
    DLinkList temp = head;
    //根据题目x<an为不会到结尾
    while (temp->next->data < x->data)
    {
        temp = temp->next;
    }
    x->next=temp->next;
    temp->next->prior=x;
    temp->next=x;
    x->prior=temp;
}