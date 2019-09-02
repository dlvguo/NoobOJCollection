#include <iostream>
#include "../../Headers/linkList.h"
using namespace std;

//考虑俩种情况 1、2
void Exchange(LinkList &A, int k)
{
    //目标节点 前驱 前前驱
    //第一个没必要换故从第二个开始才有前面考虑
    Node *p = A->next, *pre = A, *prr = NULL;
    //一开始判断特殊俩个,若个数不够2个不处理
    if (p && pre)
    {
        if (p->data == k)
        {
            A = p;
            pre->next = p->next;
            A->next = pre;
            prr = A;
            p = pre->next;
        }
        else
        {
            prr = pre;
            pre = p;
            p = p->next;
        }
        while (p)
        {
            if (p->data == k)
            {
                prr->next = p;
                pre->next = p->next;
                p->next = pre;
                prr = p;
                p = pre->next;
            }
            else
            {
                prr = pre;
                pre = p;
                p = p->next;
            }
        }
    }
}

int main()
{
    freopen("C:/NoobOJCollection/BaiPiShu/XianXingBiao/P91-14.txt", "r", stdin);
    LinkList L;
    InitList(L, false);
    PrintList(L);
    Exchange(L, 6);
    PrintList(L);
    return 0;
}