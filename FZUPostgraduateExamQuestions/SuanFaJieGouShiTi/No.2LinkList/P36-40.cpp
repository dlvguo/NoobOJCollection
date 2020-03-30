#include <iostream>
using namespace std;

typedef struct dnode
{
    dnode *prior,*next;
    int data;
}*DLinkList;


bool MoveMax(DLinkList &list)
{
    if(list->next==list)
        return;
    //rear 表示末尾 p表示从正向开始
    DLinkList rear=list->prior,p=list->next;
    //如果节点个数为奇数 若rear==p 表示到中间点 偶数 则 p->next==rear
    while (rear!=p&&p->next!=rear)
    {
        if(rear->data!=p->data)
            return false;
    }
    return true;
}