#include <iostream>
#include "../../Headers/linkList.h"
using namespace std;

int abs(int a)
{
    return a < 0 ? a * -1 : a;
}

void delemore(LinkList A, int n)
{
    //用数组保存出现过的数
    int *a = new int[n + 1]; //包括0
    for (int i = 0; i <= n; i++)
    {
        a[i] = 0;
    }

    a[abs(A->data)] = 1;
    //从第二个开始遍历
    Node *pre = A, *p = A->next;
    while (p)
    {
        //如果存在则删除
        if (a[abs(p->data)])
        {
            pre->next = p->next;
            delete p;
            p = pre->next;
        }
        else
        {
            a[abs(p->data)] = 1;
            pre = p;
            p = p->next;
        }
    }
}

int main()
{
    freopen("C:/NoobOJCollection/WandDao/No2.XianXingBiao/P40-23.txt", "r", stdin);
    LinkList A;
    InitList(A, false);
    delemore(A,3);
    PrintList(A,false);
    
}
