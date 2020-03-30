#include <iostream>
using namespace std;

typedef struct dnode
{
    dnode *prior,*next;
    int data;
}*DLinkList;


void MoveMax(DLinkList &head)
{
    //假设head不带头节点
    DLinkList rear=head->next,point=head;
    while (rear)
    {
        if(rear->data>point->data)
            point=rear;
        rear=rear->next;
    }
    //先判断point是不是最末尾节点 如果是 直接指向head即可
    if(point->next==NULL){
        point->prior->next=NULL;
        point->next=head;
        head->prior=point;
        head=point;
    }
    //否则
    else{
        //使point后继指向前继 前继指向后继
        point->next->prior=point->prior;
        point->prior->next=point->next;
        point->next=head;
        point->prior=NULL;
        head->prior=point;
        head=point;
    }
}