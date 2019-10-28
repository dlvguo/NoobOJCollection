#include <iostream>
#include "../../Headers/linkList.h"
using namespace std;

//有序算并集
void MergeU(LinkList &ha, LinkList hb)
{
    //rear表示新链表的末尾元素 初始为NULL
    LinkList rear=ha,pa=ha,pb=hb;
    if(pa->data>pb->data){
        //说明第一个最小元素在hb中 pb作为ha的表头
        rear=pb;
        pb=pb->next;
        rear->next=ha;
        ha=rear;
    }
    else{
        rear=ha->next;
        pa=pa->next;
    }

    while (pa&&pb)
    {
        if(pa->data==pb->data){
            rear=rear->next;
            pa=pa->next;
            pb=pb->next;
        }
        else if(pa->data<pb->data){
            rear=pa;
            pa=pa->next;
        }
        else{
            //将pb插入到末尾中
            LinkList temp=pb;
            pb=pb->next;
            temp->next=rear->next;
            rear->next=temp;
            rear=temp;
        }
    }
}