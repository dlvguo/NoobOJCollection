#include <iostream>
#include"../../Headers/linkList.h"
using namespace std;

//设带有头节点
void SelectSort(LinkList head){
    LinkList p=head->next;
    while (p->next)
    {
        LinkList temp=p,pp=p->next;
        while (pp)
        {
            if(pp->data<temp->data)
                temp=pp;
            pp=pp->next;
        }
        if(p!=temp){
            //交换数值等同于交换节点
            swap(p->data,temp->data);
        }
        p=p->next;
    }
}