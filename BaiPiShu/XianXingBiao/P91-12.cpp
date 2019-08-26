#include <iostream>
#include "../Headers/linkList.h"
using namespace std;

Node *FindLast(LinkList L, int k)
{
    int count = 1;
    Node *head = L, *rear = L;
    //注意次序问题 避免出现的错的数字
    while (rear->next)
    {
        if (count < k)
        {
            count++;
            rear = rear->next;
        }
        else
        {
            head = head->next;
            rear = rear->next;
        }
    }
    return count==k?head:NULL;
}

int main()
{
    freopen("C:/NoobOJCollection/BaiPiShu/XianXingBiao/P91-12.txt", "r", stdin);
    LinkList L;
    InitList(L,false);
    Node *N=FindLast(L,7);
    cout<<N->data;
    return 0;
}