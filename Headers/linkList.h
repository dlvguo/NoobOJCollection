#include <iostream>
#include <cstring>
using namespace std;
typedef int Element;

typedef struct DNode
{
    Element data;
    DNode *next;
    DNode *prior;
} * DLinkList;

#pragma region //单链表部分

typedef struct Node
{
    Element data;
    Node *next;
} * LinkList;

//判断是否为空
bool IsEmpty(LinkList L)
{
    return L == NULL;
}

//初始化链表 带头节点
void InitList(LinkList &L, bool isHead = true, int num = 0)
{
    if (isHead)
    {
        L = new Node;
        L->data = -1;
        L->next = NULL;
    }
    else
    {
        L = new Node;
        L->data = -1;
    }
    Node *rear = L;
    int a;
    if (num)
    {
        while (num--)
        {
            cin>>a;
            if (!isHead && L->data == -1)
            {
                L->data = a;
                L->next = NULL;
                continue;
            }
            Node *d = new Node;
            d->data = a;
            d->next = NULL;
            rear->next = d;
            rear = rear->next;
        }
        return;
    }
    while (cin >> a)
    {
        if (!isHead && L->data == -1)
        {
            L->data = a;
            L->next = NULL;
            continue;
        }
        Node *d = new Node;
        d->data = a;
        d->next = NULL;
        rear->next = d;
        rear = rear->next;
    }
}

//初始化链表 带头节点
void InitList(LinkList &L, int b[], int l, bool isHead = true)
{
    int i = 0;
    //初始化
    L = new Node;
    L->data = -1;
    L->next = NULL;
    Node *rear = L;
    int a;
    while (i < l)
    {
        if (!isHead && L->data == -1)
        {
            L->data = b[i++];
            L->next = NULL;

            continue;
        }
        Node *d = new Node;
        d->data = b[i++];
        d->next = NULL;
        rear->next = d;
        rear = rear->next;
    }
}

//获得元素个数
int GetLength(LinkList L)
{
    int count = 0;
    while (L)
    {
        count++;
        L = L->next;
    }
    return count;
}

//获取某个位置的元素
Node *GetEle(LinkList lst, int i)
{
    int cout = 0;
    if (i < 1)
        return NULL;
    while (cout < i && lst)
    {
        lst = lst->next;
        cout++;
        /* code */
    }
    return lst;
}

//获取元素位置
int LocateElem(LinkList L, Node *n)
{
    int i = 1;
    while (L != n && L)
    {
        i++;
        L = L->next;
    }
    if (!L)
        i = -1;
    return i;
}

//插入非有头节点 单链表
void ListInsert(LinkList &L, int i, Node *e)
{
    if (i < 0)
        return;
    int count = 1;
    if (i == 1)
    {
        e->next = L;
        L = e;
        return;
    }
    Node *pf = NULL, *p = L;
    while (p && count < i)
    {
        count++;
        pf = p;
        p = p->next;
        /* code */
    }
    if (count == i)
    {
        e->next = p;
        pf->next = e;
        return;
    }
    else if (count == i - 1)
    {
        p->next = e;
        e->next = NULL;
    }
}

//单链表元素删除
void ListDelete(LinkList &L, int i, Node *&e)
{
    if (i < 0)
        return;
    if (i == 1)
    {
        Node *p = L;
        e->data = p->data;
        e->next = p->next;
        L = L->next;
        delete p;
        return;
    }
    int count = 1;
    Node *pf = NULL, *p = L;
    while (p && count < i)
    {
        i++;
        pf = p;
        p = p->next;
    }
    if (count == i)
    {
        e->data = p->data;
        e->next = p->next;
        pf->next = p->next;
        free(p);
    }
}

//输出所有值
void PrintList(LinkList L, bool isHead = true)
{
    if (isHead)
        L = L->next;
    while (L)
    {
        cout << L->data << " ";
        L = L->next;
    }
    cout << endl;
}

#pragma endregion
