#include <iostream>
using namespace std;

typedef struct dnode
{
    dnode *prior,*next;
    int data;
}*DLinkList;


void SLinkConvertToDLink(DLinkList &head)
{
    //首先找到双链表尾节点
    DLinkList rear=head->next,pre=head;
    while (rear!=head)
    {
        rear->prior=pre;
        pre=rear;
        rear=rear->next;
    }
    //此时pre为尾节点 让head的prior指向pre即可
    head->prior=pre;
}
