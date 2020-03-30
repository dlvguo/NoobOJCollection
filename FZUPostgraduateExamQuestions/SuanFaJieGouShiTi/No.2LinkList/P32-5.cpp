#include <iostream>
#include "../../Headers/linkList.h"
using namespace std;

//取绝对值
int abs(int a){
    return a>0?a:-1*a;
}

void Delete(LinkList head,int m,int n)
{
    //存储0-n出现的数
    int *dig=new int[n+1];
    LinkList pre=head,p=head->next;
    while (p)
    {
        int data=abs(p->data);
        if(dig[data]){
            //删除操作
            pre->next=p->next;
            delete p;
            p=pre;
        }
        else{
            dig[data]=1;
        }
        pre=p;
        p=p->next;
    }
}