#include <iostream>
#include "../../Headers/linkList.h"
using namespace std;

void DeleteMin(LinkList head)
{
    //使用插入排序法
    LinkList rear = head->next,pre=head,point=rear,pointpre=head;
    while (rear)
    {
        if(rear->data<=point->data){
            point=rear;
            pointpre=pre;
        }
        pre=rear;
        rear=rear->next;
    }
    pointpre->next=point->next;
    delete point;
}