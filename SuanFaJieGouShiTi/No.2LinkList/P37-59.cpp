#include <iostream>
#include <cstring>
using namespace std;

typedef struct node
{
    char *data;
    int count;
    node *next;
} * LinkList;

//每次变化都按次数排序 交换数据内容即可
void ChangePos(LinkList head, LinkList p)
{
    LinkList temp = head->next, pre = head;
    while (temp != p && temp->data >= p->data)
    {
        pre = temp;
        temp = temp->next;
    }
    if (temp == p)
        return;
    swap(temp->count, p->count);
    swap(temp->data, p->data);
}

//判断是否存在若存在 节点count++
bool Search(LinkList head, char *s)
{
    LinkList point = head->next;
    while (point)
    {
        if (!strcmp(point->data, s))
        {
            point->count++;
            ChangePos(head,point);
            return false;
        }
    }
    return true;
}

void InPutWords(LinkList &head,int k)
{
    //设head为头节点
    head = new node;
    head->next = NULL;
    LinkList rear = head;
    char *s;
    while (cin >> s)
    {
        if (Search(head, s))
        {
            LinkList n = new node;
            n->data = s;
            n->next = NULL;
            rear->next = n;
            rear = rear->next;
        }
    }
    rear=head->next;
    while (k--)
    {
        cout<<rear->data;
        rear=rear->next;
    }
    
}
