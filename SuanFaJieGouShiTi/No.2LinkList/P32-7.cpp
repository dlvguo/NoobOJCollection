#include <iostream>
#include "../../Headers/linkList.h"
using namespace std;

//a为升序序列 b为降序序列
LinkList Union(LinkList a, LinkList b)
{
    //首先将b入栈 假设栈足够大
    LinkList stackb[], p = b;
    int top = -1;
    while (p)
    {
        stackb[++top]=p;
        p=p->next;
    }
    LinkList head=NULL,rear;
    p=a;
    while (p&&top!=-1)
    {
        if(head==NULL){
            //注意实时把尾巴变NULL
            if(stackb[top]->data>p->data){
                head=rear=p;
                p=p->next;
                rear->next=NULL;
            }
            else{
                head=rear=stackb[top--];
                rear->next=NULL;
            }
            continue;
        }
        if(stackb[top]->data>p->data){
            rear->next=p;
            rear=rear->next;
            p=p->next;
            rear->next=NULL;
        }
        else{
            rear->next=stackb[top--];
            rear=rear->next;
        }
    }
    //之后要么俩个链表都为空 要么只有一个存在
    if(p)
        rear->next=p;
    while (top!=-1)
    {
        rear->next=stackb[top--];
        rear=rear->next;
        rear->next=NULL;
    }
}