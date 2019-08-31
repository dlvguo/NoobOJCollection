#include <iostream>
#include "../../Headers/dlinkList.h"
using namespace std;

void Reverse(DLinkList &D)
{
    //因为至少三个 因此从第二个开始往前面倒置
    //p为目标点，pend为插入后继点，pre为前驱的前驱结点一直不变为尾节点,rear为尾巴节点
    //当目标点为末尾的时候即ppre 则转置完成 此时把最尾巴换成头节点即可
    DNode *p = D->next, *pre = D->prior, *pend = D,*rear=D;
    while (p != pre)
    {
        //使目标点p前驱与p后继相连
        rear->next=p->next;
        p->next->prior=rear;
        //目标点p插入到pre之前
        p->next=pend;
        pre->next=p;
        p->prior=pre;
        pend->prior=p;
        //此时插入点变成p
        //目标点为尾巴的下一个节点
        pend=p;
        p=rear->next;
    }
    //此时置换只差末尾,这时候末尾为头节点
    D=p;
}

int main()
{
    freopen("C:/NoobOJCollection/BaiPiShu/XianXingBiao/P91-20.txt", "r", stdin);
    DLinkList L;
    InitDLinkLst(L, false, true);
    Reverse(L);
    PrintDLinkList(L, true);
    return 0;
}