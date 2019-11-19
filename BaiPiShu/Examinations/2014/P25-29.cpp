#include <iostream>
using namespace std;

typedef struct Node
{
    Node *next;
    int data;
} * LinkList;

//假设带有头节点的链表
void Distinct(LinkList head)
{
    Node *pre = head, *p = head->next;
    while (p)
    {
        //表示重复
        if (p->data == pre->data)
        {
            pre->next=p->next;
            delete p;
            p=pre->next;
        }
        else{
            pre=p;
            p=p->next;
        }
    }
}