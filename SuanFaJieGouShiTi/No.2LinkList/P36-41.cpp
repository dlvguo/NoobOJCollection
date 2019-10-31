#include <iostream>
#include"../../Headers/linkList.h"
using namespace std;


void HHH(LinkList &a,LinkList &b,int i,int len,int j)
{
    //找到pre做为i-1的前继节点 先做i-1检索，p作为第i个元素
    LinkList pre=a,p;
    for(int k=2;k<i;k++){
        pre=pre->next;
    }
    while (pre->next&&len--)
    {
        p=pre->next;
        pre->next=p->next;
        free(p);
    }
    //此时pre当做a的最末尾元素
    while (pre->next)
    {
        pre=pre->next;
    }
    
    //找到b中的j-1元素插入
    LinkList preb=b;
     for(int k=2;k<j;k++){
        preb=preb->next;
    }
    pre->next=preb->next;
    preb->next=a;
}
