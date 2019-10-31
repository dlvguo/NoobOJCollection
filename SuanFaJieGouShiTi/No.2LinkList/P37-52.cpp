#include <iostream>
#include "../../Headers/linkList.h"
using namespace std;

void Judge(LinkList p)
{
    //从p下一个开始为a1 开始不断创建a1 a2相同的节点 依次插入在p->next 类似头插法即可构造
    LinkList a=p->next;
    while (a!=p)
    {
        LinkList n=new Node;
        n->data=a->data;
        n->next=p->next;
        p->next=n;
        a=a->next;
    }
}
