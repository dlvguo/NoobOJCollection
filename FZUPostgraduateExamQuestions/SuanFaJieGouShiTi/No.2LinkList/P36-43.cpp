#include <iostream>
#include "../../Headers/linkList.h"
using namespace std;

bool Judge(LinkList head)
{
    //首先找到双链表尾节点
    int i=2;
    LinkList pre=head,p=head->next;
    while (p)
    {
        if(p->data!=i*i-pre->data)
            return false;
        i++;
        pre=p;
        p=p->next;
    }
    return true;
}
