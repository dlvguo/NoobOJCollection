#include <iostream>
#include "../../Headers/linkList.h"
using namespace std;

void DeleteMax(LinkList &head)
{
    while (head->next)
    {
        LinkList pre=head,p=head->next,max=p,maxpre=head;
        while (p)
        {
            if(p->data>max->data){
                maxpre=pre;
                max=p;
            }
            pre=p;
            p=p->next;
        }
        maxpre->next=max->next;
        delete max;
    }
    delete head;
}