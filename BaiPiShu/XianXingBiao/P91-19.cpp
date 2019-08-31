#include <iostream>
#include "../../Headers/linkList.h"
using namespace std;

struct Stack
{
    int a[500];
    int bottom = 0, top = 0;
    bool IsEmpty()
    {
        return bottom == top;
    }
    void Push(int b)
    {
        a[top++] = b;
    }
    int Pop()
    {
        return a[--top];
    }
};

//考虑俩种情况 1、2
bool JudgeCenter(LinkList &h)
{
    int count = 0, mid;
    Node *p = h;
    while (p)
    {
        count++;
        p = p->next;
    }
    //奇数和偶数对称选择不一样
    mid = count % 2 ? count / 2 + 2 : count / 2 + 1;
    //使用栈
    Stack s;
    count = 0;
    p = h;
    while (p)
    {
        count++;
        if (count >= mid)
        {
            s.Push(p->data);
        }
        p = p->next;
    }
    p = h;
    while (!s.IsEmpty())
    {
        if(p->data!=s.Pop())
            return false;
        p=p->next;
    }
    return true;
}

int main()
{
    freopen("C:/NoobOJCollection/BaiPiShu/XianXingBiao/P91-19.txt", "r", stdin);
    LinkList L;
    InitList(L, false);
    cout << JudgeCenter(L) << endl;
    PrintList(L, false);
    return 0;
}