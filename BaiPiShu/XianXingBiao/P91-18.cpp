#include <iostream>
#include "../../Headers/linkList.h"
using namespace std;

//考虑俩种情况 1、2
void MoveMin(LinkList &L)
{
    Node *p=L,*pre=NULL,*temp=L,*tempre=NULL;
    while (p)
    {
        if(p->data<temp->data){
            tempre=pre;
            temp=p;
        }
        pre=p;
        p=p->next;
    }
    if(tempre){
        tempre->next=temp->next;
        temp->next=L;
        L=temp;
    }
}

int main()
{
    freopen("C:/NoobOJCollection/BaiPiShu/XianXingBiao/P91-18.txt", "r", stdin);
    LinkList L;
    InitList(L,false);
    MoveMin(L);
    PrintList(L,false);
    return 0;
}